#include "CSEMachine.h"
#include <stdexcept>
#include <cmath>

using namespace std;


CSEMachine::CSEMachine(shared_ptr<TreeNode> root) : env_counter(0) {
    PE = make_shared<Environment>(env_counter++, nullptr);
    current_env = PE;

    deltas.push_back({});

    flatten(root, 0);

    auto env_item = make_shared<CSEItem>(ItemType::ENV_MARKER, "0");
    env_item->env_ptr = PE;

    control.push_back(env_item);

    for (auto it = deltas[0].rbegin(); it != deltas[0].rend(); ++it)
        control.push_back(*it);

    stack.push_back(env_item);
}


void CSEMachine::flatten(shared_ptr<TreeNode> node, int idx) {
    if (!node) return;

    if (node->type == "lambda") {
        int next = deltas.size();
        deltas.push_back({});

        flatten(node->child->sibling, next);

        auto item = make_shared<CSEItem>(ItemType::LAMBDA);
        item->delta_index = next;

        auto var = node->child;

        if (var->type == ",") {
            for (auto c = var->child; c; c = c->sibling)
                item->bound_vars.push_back(c->value);
        } else {
            item->bound_var = var->value;
        }

        deltas[idx].push_back(item);
    }

    else if (node->type == "->") {
        auto B = node->child;
        auto T = B->sibling;
        auto E = T->sibling;

        flatten(B, idx);

        int d1 = deltas.size();
        deltas.push_back({});
        flatten(T, d1);

        int d2 = deltas.size();
        deltas.push_back({});
        flatten(E, d2);

        auto beta = make_shared<CSEItem>(ItemType::OPERATOR, "beta");
        beta->bound_vars = {to_string(d1), to_string(d2)};

        deltas[idx].push_back(beta);
    }

    else {
        for (auto c = node->child; c; c = c->sibling)
            flatten(c, idx);

        deltas[idx].push_back(createItemFromNode(node));
    }
}


shared_ptr<CSEItem> CSEMachine::createItemFromNode(shared_ptr<TreeNode> node) {
    if (node->type == "gamma")
        return make_shared<CSEItem>(ItemType::GAMMA);

    if (node->type == "<INTEGER>")
        return make_shared<CSEItem>(ItemType::INTEGER, node->value);

    if (node->type == "<STRING>")
        return make_shared<CSEItem>(ItemType::STRING, node->value);

    if (node->type == "true" || node->type == "false")
        return make_shared<CSEItem>(ItemType::TRUTH_VALUE, node->type);

    if (node->type == "nil")
        return make_shared<CSEItem>(ItemType::NIL);

    if (node->type == "dummy" || node->type == "()")
        return make_shared<CSEItem>(ItemType::DUMMY);

    if (node->type == "Ystar")
        return make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Ystar");

    if (node->type == "tau") {
        auto item = make_shared<CSEItem>(ItemType::TUPLE, "tau");

        int count = 0;
        for (auto c = node->child; c; c = c->sibling)
            count++;

        item->bound_vars.push_back(to_string(count));
        return item;
    }

    if (node->type == "<IDENTIFIER>") {
        static const set<string> prims = {
            "Print","Stern","Stem","Conc","Order","Null",
            "Isinteger","Isstring","Istuple","Istruthvalue",
            "Isfunction","ItoS","Cond","aug","Ystar"
        };

        if (prims.count(node->value))
            return make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, node->value);

        return make_shared<CSEItem>(ItemType::IDENTIFIER, node->value);
    }

    return make_shared<CSEItem>(ItemType::OPERATOR, node->type);
}

void CSEMachine::evaluate() {
    while (!control.empty()) {

        auto item = control.back();
        control.pop_back();

        if (item->type == ItemType::INTEGER ||
            item->type == ItemType::STRING ||
            item->type == ItemType::TRUTH_VALUE ||
            item->type == ItemType::DUMMY ||
            item->type == ItemType::NIL ||
            item->type == ItemType::CLOSURE ||
            item->type == ItemType::PRIMITIVE_FUNC ||
            item->type == ItemType::ETA_CLOSURE ||
            (item->type == ItemType::TUPLE && item->value != "tau")) {

            stack.push_back(item);
        }

        else if (item->type == ItemType::IDENTIFIER) {
            auto val = current_env->lookup(item->value);

            if (!val) {
                if (item->value == "Print")
                    stack.push_back(make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Print"));
                else
                    throw runtime_error("Undeclared identifier: " + item->value);
            } else {
                stack.push_back(val);
            }
        }

        else if (item->type == ItemType::LAMBDA) {
            auto closure = make_shared<CSEItem>(ItemType::CLOSURE);
            closure->env_ptr = current_env;
            closure->delta_index = item->delta_index;
            closure->bound_var = item->bound_var;
            closure->bound_vars = item->bound_vars;
            stack.push_back(closure);
        }

        else if (item->type == ItemType::GAMMA) {
            if (stack.size() < 2)
                throw runtime_error("Stack underflow in GAMMA");

            auto rand = stack.back(); stack.pop_back();
            auto rator = stack.back(); stack.pop_back();

            if (rator->type == ItemType::CLOSURE) {
                auto new_env = make_shared<Environment>(env_counter++, rator->env_ptr);

                if (!rator->bound_vars.empty() && rand->type == ItemType::TUPLE) {
                    for (size_t i = 0; i < rator->bound_vars.size(); i++)
                        new_env->bindings[rator->bound_vars[i]] = rand->tuple_items[i];
                } else {
                    new_env->bindings[rator->bound_var] = rand;
                }

                auto env_marker = make_shared<CSEItem>(ItemType::ENV_MARKER, to_string(new_env->id));
                env_marker->previous_env = current_env;

                current_env = new_env;

                control.push_back(env_marker);
                stack.push_back(env_marker);

                auto &d = deltas[rator->delta_index];
                for (auto it = d.rbegin(); it != d.rend(); ++it)
                    control.push_back(*it);
            }

            else if (rator->type == ItemType::PRIMITIVE_FUNC) {
                if (rator->value == "Ystar") {
                    auto eta = make_shared<CSEItem>(ItemType::ETA_CLOSURE);
                    eta->closure_ptr = rand;
                    stack.push_back(eta);
                } else {
                    stack.push_back(rand);
                    applyPrimitive(rator->value);
                }
            }

            else if (rator->type == ItemType::ETA_CLOSURE) {
                control.push_back(make_shared<CSEItem>(ItemType::GAMMA));
                control.push_back(rand);
                control.push_back(make_shared<CSEItem>(ItemType::GAMMA));
                stack.push_back(rator->closure_ptr);
                stack.push_back(rator);
            }
        }

        else if (item->type == ItemType::ENV_MARKER) {
            current_env = item->previous_env;

            auto result = stack.back(); stack.pop_back();
            stack.pop_back(); // marker
            stack.push_back(result);
        }

        else if (item->type == ItemType::TUPLE && item->value == "tau") {
            int n = stoi(item->bound_vars[0]);

            auto tuple = make_shared<CSEItem>(ItemType::TUPLE);

            for (int i = 0; i < n; i++) {
                tuple->tuple_items.insert(tuple->tuple_items.begin(), stack.back());
                stack.pop_back();
            }

            stack.push_back(tuple);
        }

        else if (item->type == ItemType::OPERATOR) {
            if (item->value == "beta") {
                auto b = stack.back(); stack.pop_back();

                int idx = (b->value == "true")
                    ? stoi(item->bound_vars[0])
                    : stoi(item->bound_vars[1]);

                auto &d = deltas[idx];
                for (auto it = d.rbegin(); it != d.rend(); ++it)
                    control.push_back(*it);
            }

            else if (item->value == "neg" || item->value == "not")
                applyUnaryOp(item->value);

            else
                applyBinaryOp(item->value);
        }
    }
}


void CSEMachine::applyPrimitive(const string& f) {
    auto rand = stack.back(); stack.pop_back();

    if (f == "Print") {
        printItem(rand);
        cout << endl;
        stack.push_back(make_shared<CSEItem>(ItemType::DUMMY));
    }
}

void CSEMachine::applyBinaryOp(const string& op) {
    auto r2 = stack.back(); stack.pop_back();
    auto r1 = stack.back(); stack.pop_back();

    if (op == "+")
        stack.push_back(make_shared<CSEItem>(ItemType::INTEGER, to_string(stoi(r1->value) + stoi(r2->value))));
}

void CSEMachine::applyUnaryOp(const string& op) {
    auto r = stack.back(); stack.pop_back();

    if (op == "not")
        stack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE, r->value == "true" ? "false" : "true"));
}

void CSEMachine::printItem(shared_ptr<CSEItem> item, bool) {
    if (item->type == ItemType::INTEGER) cout << item->value;
    else if (item->type == ItemType::STRING) cout << item->value;
    else if (item->type == ItemType::TRUTH_VALUE) cout << item->value;
}
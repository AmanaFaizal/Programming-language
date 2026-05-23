#include "CSEMachine.h"
#include <stdexcept>
#include <cmath>

using namespace std;

// ─────────────────────────────────────────────────────────────────────────────
//  Constructor: build delta[0] from the standardized tree and prime the control
// ─────────────────────────────────────────────────────────────────────────────
CSEMachine::CSEMachine(shared_ptr<TreeNode> root) : envCounter(0) {
    primEnv   = make_shared<Environment>(envCounter++, nullptr);
    activeEnv = primEnv;

    deltas.push_back(vector<shared_ptr<CSEItem>>());
    flatten(root, 0);

    auto envMark    = make_shared<CSEItem>(ItemType::ENV_MARKER, "0");
    envMark->envPtr = primEnv;

    control.push_back(envMark);
    for (auto it = deltas[0].rbegin(); it != deltas[0].rend(); ++it)
        control.push_back(*it);

    valueStack.push_back(envMark);
}

// ─────────────────────────────────────────────────────────────────────────────
//  flatten: walk the standardized tree and populate delta bodies
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::flatten(shared_ptr<TreeNode> node, int curDelta) {
    if (!node) return;

    if (node->type == "lambda") {
        int newDelta = (int)deltas.size();
        deltas.push_back(vector<shared_ptr<CSEItem>>());
        flatten(node->child->sibling, newDelta);

        auto lam       = make_shared<CSEItem>(ItemType::LAMBDA);
        lam->deltaIdx  = newDelta;

        auto varNode = node->child;
        if (varNode->type == ",") {
            for (auto c = varNode->child; c; c = c->sibling)
                lam->boundVars.push_back(c->value);
        } else {
            lam->boundVar = varNode->value;
        }
        deltas[curDelta].push_back(lam);
        return;
    }

    if (node->type == "->") {
        auto condNode = node->child;
        auto thenNode = condNode->sibling;
        auto elseNode = thenNode->sibling;

        flatten(condNode, curDelta);

        int thenDelta = (int)deltas.size();
        deltas.push_back(vector<shared_ptr<CSEItem>>());
        flatten(thenNode, thenDelta);

        int elseDelta = (int)deltas.size();
        deltas.push_back(vector<shared_ptr<CSEItem>>());
        flatten(elseNode, elseDelta);

        auto beta = make_shared<CSEItem>(ItemType::OPERATOR, "beta");
        beta->boundVars.push_back(to_string(thenDelta));
        beta->boundVars.push_back(to_string(elseDelta));
        deltas[curDelta].push_back(beta);
        return;
    }

    // General node: recurse into children first (post-order)
    for (auto c = node->child; c; c = c->sibling)
        flatten(c, curDelta);

    deltas[curDelta].push_back(nodeToItem(node));
}

// ─────────────────────────────────────────────────────────────────────────────
//  nodeToItem: convert a tree node into a CSEItem
// ─────────────────────────────────────────────────────────────────────────────
shared_ptr<CSEItem> CSEMachine::nodeToItem(shared_ptr<TreeNode> node) {
    const string& t = node->type;

    if (t == "gamma")   return make_shared<CSEItem>(ItemType::GAMMA);
    if (t == "<INTEGER>") return make_shared<CSEItem>(ItemType::INTEGER,     node->value);
    if (t == "<STRING>")  return make_shared<CSEItem>(ItemType::STRING,      node->value);
    if (t == "true" || t == "false")
                          return make_shared<CSEItem>(ItemType::TRUTH_VALUE,  t);
    if (t == "nil")       return make_shared<CSEItem>(ItemType::NIL);
    if (t == "dummy" || t == "()")
                          return make_shared<CSEItem>(ItemType::DUMMY);
    if (t == "Ystar")     return make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Ystar");

    if (t == "tau") {
        auto item = make_shared<CSEItem>(ItemType::TUPLE, "tau");
        int n = 0;
        for (auto c = node->child; c; c = c->sibling) ++n;
        item->boundVars.push_back(to_string(n));
        return item;
    }

    if (t == "<IDENTIFIER>") {
        static const vector<string> prims = {
            "Print","Stern","Stem","Conc","Order","Null",
            "Isinteger","Isstring","Istuple","Istruthvalue",
            "Isfunction","ItoS","Cond","aug","Ystar"
        };
        const string& v = node->value;
        for (auto& p : prims)
            if (v == p) return make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, v);
        return make_shared<CSEItem>(ItemType::IDENTIFIER, v);
    }

    return make_shared<CSEItem>(ItemType::OPERATOR, t);
}

// ─────────────────────────────────────────────────────────────────────────────
//  evaluate: main CSE reduction loop
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::evaluate() {
    while (!control.empty()) {
        auto item = control.back();
        control.pop_back();

        switch (item->type) {

        // ── Values: push straight onto the stack ─────────────────────────
        case ItemType::INTEGER:
        case ItemType::STRING:
        case ItemType::TRUTH_VALUE:
        case ItemType::DUMMY:
        case ItemType::NIL:
        case ItemType::CLOSURE:
        case ItemType::PRIMITIVE_FUNC:
        case ItemType::ETA_CLOSURE:
            valueStack.push_back(item);
            break;

        case ItemType::TUPLE:
            // Built tuples (not tau-markers) go straight to the stack
            if (item->value != "tau")
                valueStack.push_back(item);
            else {
                // tau-marker: collect n values from stack
                int n = stoi(item->boundVars[0]);
                if ((int)valueStack.size() < n)
                    throw runtime_error("Stack underflow in tau");
                auto tup = make_shared<CSEItem>(ItemType::TUPLE);
                for (int i = 0; i < n; ++i) {
                    tup->elements.insert(tup->elements.begin(), valueStack.back());
                    valueStack.pop_back();
                }
                valueStack.push_back(tup);
            }
            break;

        // ── Identifier: look up in active environment ─────────────────────
        case ItemType::IDENTIFIER: {
            auto val = activeEnv->lookup(item->value);
            if (!val) {
                if (item->value == "Print")
                    valueStack.push_back(make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Print"));
                else
                    throw runtime_error("Undeclared identifier: " + item->value);
            } else {
                valueStack.push_back(val);
            }
            break;
        }

        // ── Lambda: capture current environment as a closure ──────────────
        case ItemType::LAMBDA: {
            auto closure        = make_shared<CSEItem>(ItemType::CLOSURE);
            closure->envPtr     = activeEnv;
            closure->deltaIdx   = item->deltaIdx;
            closure->boundVar   = item->boundVar;
            closure->boundVars  = item->boundVars;
            valueStack.push_back(closure);
            break;
        }

        // ── Gamma: function application ───────────────────────────────────
        case ItemType::GAMMA: {
            if (valueStack.size() < 2)
                throw runtime_error("Stack underflow in GAMMA");

            auto arg  = valueStack.back(); valueStack.pop_back();
            auto func = valueStack.back(); valueStack.pop_back();

            if (func->type == ItemType::CLOSURE) {
                // Create a new environment bound to the closure's env
                auto newEnv = make_shared<Environment>(envCounter++, func->envPtr);

                if (!func->boundVars.empty() && arg->type == ItemType::TUPLE) {
                    for (size_t i = 0; i < func->boundVars.size(); ++i)
                        newEnv->bindings[func->boundVars[i]] = arg->elements[i];
                } else {
                    newEnv->bindings[func->boundVar] = arg;
                }

                auto mark         = make_shared<CSEItem>(ItemType::ENV_MARKER, to_string(newEnv->id));
                mark->envPtr      = newEnv;
                mark->callerEnv   = activeEnv;
                activeEnv         = newEnv;

                control.push_back(mark);
                valueStack.push_back(mark);

                auto& body = deltas[func->deltaIdx];
                for (auto it = body.rbegin(); it != body.rend(); ++it)
                    control.push_back(*it);

            } else if (func->type == ItemType::PRIMITIVE_FUNC) {
                const string& name = func->value;

                if (name == "Ystar") {
                    auto eta         = make_shared<CSEItem>(ItemType::ETA_CLOSURE);
                    eta->etaClosure  = arg;
                    valueStack.push_back(eta);

                } else if (name == "Cond") {
                    auto partial = make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Cond1");
                    partial->elements.push_back(arg);   // B
                    valueStack.push_back(partial);

                } else if (name == "Cond1") {
                    auto partial = make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Cond2");
                    partial->elements.push_back(func->elements[0]); // B
                    partial->elements.push_back(arg);               // T
                    valueStack.push_back(partial);

                } else if (name == "Cond2") {
                    auto& B  = func->elements[0];
                    auto& T  = func->elements[1];
                    auto  branch = (B->value == "true") ? T : arg;
                    control.push_back(make_shared<CSEItem>(ItemType::GAMMA));
                    valueStack.push_back(branch);
                    valueStack.push_back(make_shared<CSEItem>(ItemType::DUMMY));

                } else if (name == "Conc1") {
                    auto res = make_shared<CSEItem>(ItemType::STRING,
                                   func->elements[0]->value + arg->value);
                    valueStack.push_back(res);

                } else if (name == "aug1") {
                    auto& base = func->elements[0];
                    auto  res  = make_shared<CSEItem>(ItemType::TUPLE);
                    if (base->type == ItemType::TUPLE)
                        res->elements = base->elements;
                    else if (base->type != ItemType::NIL)
                        res->elements.push_back(base);
                    res->elements.push_back(arg);
                    valueStack.push_back(res);

                } else {
                    // Generic primitive: push arg back and dispatch
                    valueStack.push_back(arg);
                    applyPrimitive(name);
                }

            } else if (func->type == ItemType::ETA_CLOSURE) {
                // Y* eta expansion
                control.push_back(make_shared<CSEItem>(ItemType::GAMMA));
                control.push_back(arg);
                control.push_back(make_shared<CSEItem>(ItemType::GAMMA));
                valueStack.push_back(func->etaClosure);
                valueStack.push_back(func);

            } else if (func->type == ItemType::TUPLE) {
                // Tuple indexing: func @ arg  (1-based)
                if (arg->type != ItemType::INTEGER)
                    throw runtime_error("Tuple index must be an integer");
                int idx = stoi(arg->value);
                valueStack.push_back(func->elements[idx - 1]);
            }
            break;
        }

        // ── ENV_MARKER: restore caller environment ────────────────────────
        case ItemType::ENV_MARKER: {
            activeEnv = item->callerEnv;
            if (valueStack.size() < 2)
                throw runtime_error("Stack underflow in ENV_MARKER");
            auto result = valueStack.back(); valueStack.pop_back();
            valueStack.pop_back();           // discard the matching marker
            valueStack.push_back(result);
            break;
        }

        // ── Operator: unary / binary / beta ──────────────────────────────
        case ItemType::OPERATOR: {
            const string& op = item->value;
            if (op == "beta") {
                auto cond = valueStack.back(); valueStack.pop_back();
                int branchIdx = (cond->value == "true")
                                ? stoi(item->boundVars[0])
                                : stoi(item->boundVars[1]);
                auto& branch = deltas[branchIdx];
                for (auto it = branch.rbegin(); it != branch.rend(); ++it)
                    control.push_back(*it);
            } else if (op == "neg" || op == "not") {
                applyUnaryOp(op);
            } else {
                applyBinaryOp(op);
            }
            break;
        }

        default:
            break;
        }
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  applyPrimitive
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::applyPrimitive(const string& name) {
    if (valueStack.empty())
        throw runtime_error("Stack underflow in applyPrimitive: " + name);

    auto arg = valueStack.back(); valueStack.pop_back();

    if (name == "Print") {
        printItem(arg);
        cout << '\n';
        valueStack.push_back(make_shared<CSEItem>(ItemType::DUMMY));

    } else if (name == "Stem") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::STRING,
                                 arg->value.substr(0, 1)));

    } else if (name == "Stern") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::STRING,
                                 arg->value.substr(1)));

    } else if (name == "Conc") {
        if (arg->type == ItemType::TUPLE) {
            string res;
            for (auto& el : arg->elements) res += el->value;
            valueStack.push_back(make_shared<CSEItem>(ItemType::STRING, res));
        } else {
            auto partial = make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Conc1");
            partial->elements.push_back(arg);
            valueStack.push_back(partial);
        }

    } else if (name == "aug") {
        auto partial = make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "aug1");
        partial->elements.push_back(arg);
        valueStack.push_back(partial);

    } else if (name == "Order") {
        int sz = (arg->type == ItemType::TUPLE) ? (int)arg->elements.size() : 0;
        valueStack.push_back(make_shared<CSEItem>(ItemType::INTEGER, to_string(sz)));

    } else if (name == "Isinteger") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            arg->type == ItemType::INTEGER ? "true" : "false"));

    } else if (name == "Isstring") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            arg->type == ItemType::STRING ? "true" : "false"));

    } else if (name == "Istuple") {
        bool ok = arg->type == ItemType::TUPLE || arg->type == ItemType::NIL;
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            ok ? "true" : "false"));

    } else if (name == "Istruthvalue") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            arg->type == ItemType::TRUTH_VALUE ? "true" : "false"));

    } else if (name == "Isfunction") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            arg->type == ItemType::CLOSURE ? "true" : "false"));

    } else if (name == "Null") {
        bool isNull = arg->type == ItemType::NIL ||
                      (arg->type == ItemType::TUPLE && arg->elements.empty());
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            isNull ? "true" : "false"));

    } else if (name == "ItoS") {
        valueStack.push_back(make_shared<CSEItem>(ItemType::STRING, arg->value));

    } else if (name == "Cond") {
        auto partial = make_shared<CSEItem>(ItemType::PRIMITIVE_FUNC, "Cond1");
        partial->elements.push_back(arg);
        valueStack.push_back(partial);
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  applyBinaryOp
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::applyBinaryOp(const string& op) {
    if (valueStack.size() < 2)
        throw runtime_error("Stack underflow in applyBinaryOp: " + op);

    auto rhs = valueStack.back(); valueStack.pop_back();
    auto lhs = valueStack.back(); valueStack.pop_back();

    auto pushInt  = [&](int v)    { valueStack.push_back(make_shared<CSEItem>(ItemType::INTEGER,     to_string(v))); };
    auto pushBool = [&](bool v)   { valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE, v ? "true" : "false")); };

    int L = 0, R = 0;
    bool numericOp = (op == "+" || op == "-" || op == "*" || op == "/" ||
                      op == "**" || op == ">" || op == ">=" || op == "<" || op == "<=" ||
                      op == "gr" || op == "ge" || op == "ls" || op == "le");
    if (numericOp) { L = stoi(lhs->value); R = stoi(rhs->value); }

    if      (op == "+")             pushInt(L + R);
    else if (op == "-")             pushInt(L - R);
    else if (op == "*")             pushInt(L * R);
    else if (op == "/")             pushInt(L / R);
    else if (op == "**")            pushInt((int)pow(L, R));
    else if (op == "eq")            pushBool(lhs->value == rhs->value);
    else if (op == "ne")            pushBool(lhs->value != rhs->value);
    else if (op == ">"  || op == "gr") pushBool(L > R);
    else if (op == ">=" || op == "ge") pushBool(L >= R);
    else if (op == "<"  || op == "ls") pushBool(L < R);
    else if (op == "<=" || op == "le") pushBool(L <= R);
    else if (op == "or")  pushBool(lhs->value == "true" || rhs->value == "true");
    else if (op == "&")   pushBool(lhs->value == "true" && rhs->value == "true");
    else if (op == "aug") {
        auto res = make_shared<CSEItem>(ItemType::TUPLE);
        if (lhs->type == ItemType::TUPLE)
            res->elements = lhs->elements;
        else if (lhs->type != ItemType::NIL)
            res->elements.push_back(lhs);
        res->elements.push_back(rhs);
        valueStack.push_back(res);
    } else {
        throw runtime_error("Unhandled binary operator: '" + op + "'");
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  applyUnaryOp
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::applyUnaryOp(const string& op) {
    if (valueStack.empty())
        throw runtime_error("Stack underflow in applyUnaryOp: " + op);

    auto arg = valueStack.back(); valueStack.pop_back();

    if (op == "not")
        valueStack.push_back(make_shared<CSEItem>(ItemType::TRUTH_VALUE,
            arg->value == "true" ? "false" : "true"));
    else if (op == "neg")
        valueStack.push_back(make_shared<CSEItem>(ItemType::INTEGER,
            to_string(-stoi(arg->value))));
}

// ─────────────────────────────────────────────────────────────────────────────
//  printItem
// ─────────────────────────────────────────────────────────────────────────────
void CSEMachine::printItem(shared_ptr<CSEItem> item, bool inConc) {
    switch (item->type) {
    case ItemType::INTEGER:      cout << item->value; break;
    case ItemType::STRING:       cout << unescapeString(item->value); break;
    case ItemType::TRUTH_VALUE:  cout << item->value; break;
    case ItemType::DUMMY:        cout << "dummy"; break;
    case ItemType::NIL:          cout << "nil"; break;
    case ItemType::CLOSURE:
        cout << "[lambda closure: " << item->boundVar << ": " << item->deltaIdx << "]";
        break;
    case ItemType::ETA_CLOSURE:  cout << "[eta closure]"; break;
    case ItemType::GAMMA:        cout << "GAMMA "; break;
    case ItemType::ENV_MARKER:   cout << "ENV(" << item->value << ") "; break;
    case ItemType::IDENTIFIER:   cout << "ID(" << item->value << ") "; break;
    case ItemType::OPERATOR:     cout << "OP(" << item->value << ") "; break;
    case ItemType::LAMBDA:       cout << "LAMBDA(" << item->deltaIdx << ") "; break;
    case ItemType::PRIMITIVE_FUNC: cout << "PRIM(" << item->value << ") "; break;
    case ItemType::TUPLE:
        cout << '(';
        for (size_t i = 0; i < item->elements.size(); ++i) {
            printItem(item->elements[i]);
            if (i + 1 < item->elements.size()) cout << ", ";
        }
        cout << ')';
        break;
    default: break;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  unescapeString: handle \\n and \\t escape sequences
// ─────────────────────────────────────────────────────────────────────────────
string CSEMachine::unescapeString(const string& s) {
    string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\\' && i + 1 < s.size()) {
            if (s[i + 1] == 'n') { out += '\n'; ++i; continue; }
            if (s[i + 1] == 't') { out += '\t'; ++i; continue; }
        }
        out += s[i];
    }
    return out;
}
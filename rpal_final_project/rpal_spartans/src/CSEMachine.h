#ifndef CSEMACHINE_H
#define CSEMACHINE_H

#include "TreeNode.h"
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iostream>
#include <set>

using namespace std;


enum class ItemType {
    INTEGER, STRING, TRUTH_VALUE, DUMMY, NIL,
    IDENTIFIER, OPERATOR,
    LAMBDA, GAMMA, ENV_MARKER, CLOSURE, ETA_CLOSURE,
    TUPLE, PRIMITIVE_FUNC
};


class Environment {
public:
    int id;
    shared_ptr<Environment> parent;
    map<string, shared_ptr<class CSEItem>> bindings;

    Environment(int env_id, shared_ptr<Environment> p)
        : id(env_id), parent(p) {}

    shared_ptr<class CSEItem> lookup(const string& name) {
        if (bindings.find(name) != bindings.end())
            return bindings[name];
        if (parent)
            return parent->lookup(name);
        return nullptr;
    }
};


class CSEItem {
public:
    ItemType type;
    string value;

    int delta_index = -1;

    shared_ptr<Environment> env_ptr;
    string bound_var;
    vector<string> bound_vars;

    vector<shared_ptr<CSEItem>> tuple_items;

    shared_ptr<Environment> previous_env;
    shared_ptr<CSEItem> closure_ptr;

    CSEItem(ItemType t, string v = "")
        : type(t), value(v) {}
};


class CSEMachine {
private:
    vector<vector<shared_ptr<CSEItem>>> deltas;
    vector<shared_ptr<CSEItem>> control;
    vector<shared_ptr<CSEItem>> stack;

    shared_ptr<Environment> current_env;
    shared_ptr<Environment> PE;
    int env_counter;

 
    void flatten(shared_ptr<TreeNode> node, int current_delta_index);
    shared_ptr<CSEItem> createItemFromNode(shared_ptr<TreeNode> node);

    void applyPrimitive(const string& func_name);
    void applyBinaryOp(const string& op);
    void applyUnaryOp(const string& op);

    string escapeString(const string& s);
    void printItem(shared_ptr<CSEItem> item, bool is_conc = false);

   
    shared_ptr<CSEItem> popStack();
    void pushStack(shared_ptr<CSEItem> item);
    void pushDelta(int deltaIndex);
    bool isPrimitiveFunction(const string& name);

public:
    CSEMachine(shared_ptr<TreeNode> root);
    void evaluate();
};

#endif 
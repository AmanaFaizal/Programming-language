#ifndef CSEMACHINE_H
#define CSEMACHINE_H

#include "TreeNode.h"
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iostream>

using namespace std;

// ─────────────────────────────────────────────
//  Item types for the control/stack elements
// ─────────────────────────────────────────────
enum class ItemType {
    INTEGER,
    STRING,
    TRUTH_VALUE,
    DUMMY,
    NIL,
    IDENTIFIER,
    OPERATOR,
    LAMBDA,
    GAMMA,
    ENV_MARKER,
    CLOSURE,
    ETA_CLOSURE,
    TUPLE,
    PRIMITIVE_FUNC
};

// ─────────────────────────────────────────────
//  Forward declarations
// ─────────────────────────────────────────────
class Environment;
class CSEItem;

// ─────────────────────────────────────────────
//  A single element on the control stack
// ─────────────────────────────────────────────
class CSEItem {
public:
    ItemType type;
    string   value;

    // Lambda / closure metadata
    int    deltaIdx;          // index into deltas[]
    string boundVar;          // single bound variable
    vector<string> boundVars; // multiple bound vars (tuple lambda)

    // Tuple elements
    vector<shared_ptr<CSEItem>> elements;

    // Environment links
    shared_ptr<Environment> envPtr;      // captured / current environment
    shared_ptr<Environment> callerEnv;   // saved caller env (ENV_MARKER)

    // Eta-closure payload
    shared_ptr<CSEItem> etaClosure;

    CSEItem(ItemType t, string v = "")
        : type(t), value(move(v)), deltaIdx(-1), envPtr(nullptr), callerEnv(nullptr) {}
};

// ─────────────────────────────────────────────
//  Evaluation environment (linked-list chain)
// ─────────────────────────────────────────────
class Environment {
public:
    int id;
    shared_ptr<Environment>          parent;
    map<string, shared_ptr<CSEItem>> bindings;

    Environment(int envId, shared_ptr<Environment> p)
        : id(envId), parent(move(p)) {}

    shared_ptr<CSEItem> lookup(const string& name) const {
        auto it = bindings.find(name);
        if (it != bindings.end()) return it->second;
        return parent ? parent->lookup(name) : nullptr;
    }
};

// ─────────────────────────────────────────────
//  CSE Machine
// ─────────────────────────────────────────────
class CSEMachine {
public:
    explicit CSEMachine(shared_ptr<TreeNode> root);
    void evaluate();

private:
    // Flattened delta bodies produced from the standardized tree
    vector<vector<shared_ptr<CSEItem>>> deltas;

    // Control list and value stack
    vector<shared_ptr<CSEItem>> control;
    vector<shared_ptr<CSEItem>> valueStack;

    // Environment management
    shared_ptr<Environment> primEnv;    // primitive (root) environment
    shared_ptr<Environment> activeEnv;  // currently active environment
    int envCounter;

    // ── Tree → control-structure flattening ──────────────────────────
    void flatten(shared_ptr<TreeNode> node, int deltaIdx);
    shared_ptr<CSEItem> nodeToItem(shared_ptr<TreeNode> node);

    // ── Rule applications ─────────────────────────────────────────────
    void applyPrimitive(const string& name);
    void applyBinaryOp(const string& op);
    void applyUnaryOp(const string& op);

    // ── Output helpers ────────────────────────────────────────────────
    void   printItem(shared_ptr<CSEItem> item, bool inConc = false);
    string unescapeString(const string& s);
};

#endif // CSEMACHINE_H
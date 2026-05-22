#ifndef STANDARDIZER_H
#define STANDARDIZER_H

#include "TreeNode.h"
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Standardizer {
private:
    shared_ptr<TreeNode> makeNode(const string& type, const string& value = "");
    shared_ptr<TreeNode> createLambda(shared_ptr<TreeNode> V, shared_ptr<TreeNode> E);
    shared_ptr<TreeNode> standardizeNode(shared_ptr<TreeNode> node);

public:
    Standardizer() {}
    shared_ptr<TreeNode> standardize(shared_ptr<TreeNode> root);
};

#endif 

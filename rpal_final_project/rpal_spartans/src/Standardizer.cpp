
#include "Standardizer.h"
#include <iostream>

using namespace std;

shared_ptr<TreeNode> Standardizer::makeNode(const string& type, const string& value) {
    return make_shared<TreeNode>(type, value);
}

shared_ptr<TreeNode> makeGamma(
    shared_ptr<TreeNode> left,
    shared_ptr<TreeNode> right)
{
    auto gamma = make_shared<TreeNode>("gamma");

    gamma->setChild(left);
    left->setSibling(right);

    return gamma;
}

vector<shared_ptr<TreeNode>> detachSiblings(shared_ptr<TreeNode> start) {
    vector<shared_ptr<TreeNode>> nodes;

    while (start) {
        auto next = start->sibling;
        start->setSibling(nullptr);
        nodes.push_back(start);
        start = next;
    }

    return nodes;
}

shared_ptr<TreeNode> Standardizer::createLambda(
    shared_ptr<TreeNode> V,
    shared_ptr<TreeNode> E)
{
    if (V->type == ",") {
        auto T = makeNode("<IDENTIFIER>", "T++");
        auto vars = detachSiblings(V->child);

        auto currentBody = E;

        for (int i = (int)vars.size() - 1; i >= 0; --i) {
            auto tupleGamma = makeNode("gamma");
            auto lambdaInner = makeNode("lambda");
            auto gammaApp = makeNode("gamma");

            auto tRef = makeNode("<IDENTIFIER>", "T++");
            auto index = makeNode("<INTEGER>", to_string(i + 1));

            tupleGamma->setChild(tRef);
            tRef->setSibling(index);

            lambdaInner->setChild(vars[i]);
            vars[i]->setSibling(currentBody);

            gammaApp->setChild(lambdaInner);
            lambdaInner->setSibling(tupleGamma);

            currentBody = gammaApp;
        }

        auto finalLambda = makeNode("lambda");
        finalLambda->setChild(T);
        T->setSibling(currentBody);

        return finalLambda;
    }

    auto lambda = makeNode("lambda");
    lambda->setChild(V);
    V->setSibling(E);

    return lambda;
}

shared_ptr<TreeNode> Standardizer::standardize(shared_ptr<TreeNode> root) {
    if (!root)
        return nullptr;

    return standardizeNode(root);
}

shared_ptr<TreeNode> Standardizer::standardizeNode(shared_ptr<TreeNode> node) {
    if (!node)
        return nullptr;

    if (node->child)
        node->child = standardizeNode(node->child);

    if (node->sibling)
        node->sibling = standardizeNode(node->sibling);

    string t = node->type;

    // =====================================================
    // let
    // =====================================================

    if (t == "let") {
        auto eq = node->child;

        if (!eq || eq->type != "=")
            return node;

        auto X = eq->child;
        auto E = X->sibling;
        auto P = eq->sibling;

        auto lambda = createLambda(X, P);
        auto gamma = makeGamma(lambda, E);

        gamma->setSibling(node->sibling);
        return gamma;
    }

    // =====================================================
    // where
    // =====================================================

    if (t == "where") {
        auto P = node->child;
        auto eq = P->sibling;

        if (!eq || eq->type != "=")
            return node;

        auto X = eq->child;
        auto E = X->sibling;

        P->setSibling(nullptr);

        auto lambda = createLambda(X, P);
        auto gamma = makeGamma(lambda, E);

        gamma->setSibling(node->sibling);
        return gamma;
    }

    // =====================================================
    // within
    // =====================================================

    if (t == "within") {
        auto eq1 = node->child;
        auto eq2 = eq1->sibling;

        if (!eq1 || !eq2)
            return node;

        auto X1 = eq1->child;
        auto E1 = X1->sibling;

        auto X2 = eq2->child;
        auto E2 = X2->sibling;

        E1->setSibling(nullptr);
        E2->setSibling(nullptr);

        auto lambda = createLambda(X1, E2);
        auto gamma = makeGamma(lambda, E1 );

        auto newEq = makeNode("=");
        newEq->setChild(X2);
        X2->setSibling(gamma);

        newEq->setSibling(node->sibling);
        return newEq;
    }

    // =====================================================
    // rec
    // =====================================================

    if (t == "rec") {
        auto eq = node->child;

        if (!eq || eq->type != "=")
            return node;

        auto X = eq->child;
        auto E = X->sibling;

        E->setSibling(nullptr);

        auto ystar = makeNode("<IDENTIFIER>", "Ystar");
        auto Xcopy = makeNode(X->type, X->value);

        auto lambda = createLambda(Xcopy, E);

        auto gamma = makeNode("gamma");
        gamma->setChild(ystar);
        ystar->setSibling(lambda);

        auto newEq = makeNode("=");
        newEq->setChild(X);
        X->setSibling(gamma);

        newEq->setSibling(node->sibling);
        return newEq;
    }

    // =====================================================
    // fcn_form
    // =====================================================

    if (t == "fcn_form") {
        auto P = node->child;
        auto V = P->sibling;

        auto vars = detachSiblings(V);

        auto E = vars.back();
        vars.pop_back();

        auto currentBody = E;

        for (int i = (int)vars.size() - 1; i >= 0; --i)
            currentBody = createLambda(vars[i], currentBody);

        auto newEq = makeNode("=");
        newEq->setChild(P);
        P->setSibling(currentBody);

        newEq->setSibling(node->sibling);
        return newEq;
    }

    // =====================================================
    // and
    // =====================================================

    if (t == "and") {
        auto comma = makeNode(",");
        auto tau = makeNode("tau");

        auto newEq = makeNode("=");
        newEq->setChild(comma);
        comma->setSibling(tau);

        auto eq = node->child;

        shared_ptr<TreeNode> firstX = nullptr;
        shared_ptr<TreeNode> lastX = nullptr;

        shared_ptr<TreeNode> firstE = nullptr;
        shared_ptr<TreeNode> lastE = nullptr;

        while (eq) {
            auto X = eq->child;
            auto E = X->sibling;

            X->setSibling(nullptr);
            E->setSibling(nullptr);

            if (!firstX) {
                firstX = lastX = X;
                firstE = lastE = E;
            }
            else {
                lastX->setSibling(X);
                lastX = X;

                lastE->setSibling(E);
                lastE = E;
            }

            eq = eq->sibling;
        }

        comma->setChild(firstX);
        tau->setChild(firstE);

        newEq->setSibling(node->sibling);
        return newEq;
    }

    // =====================================================
    // @
    // =====================================================

    if (t == "@") {
        auto E1 = node->child;
        auto N = E1->sibling;
        auto E2 = N->sibling;

        E1->setSibling(nullptr);
        N->setSibling(nullptr);
        E2->setSibling(nullptr);

        auto gamma2 = makeGamma(N, E1);
        auto gamma1 = makeGamma(gamma2, E2);

        gamma1->setSibling(node->sibling);
        return gamma1;
    }

    // =====================================================
    // lambda
    // =====================================================

    if (t == "lambda") {
        auto first = node->child;

        if (!first)
            return node;

        // tuple lambda
        if (first->type == ",") {
            auto E = first->sibling;
            first->setSibling(nullptr);

            auto result = createLambda(first, E);
            result->setSibling(node->sibling);

            return result;
        }

        // multiple variables
        if (first->sibling && first->sibling->sibling) {
            auto vars = detachSiblings(first);

            auto E = vars.back();
            vars.pop_back();

            auto currentBody = E;

            for (int i = (int)vars.size() - 1; i >= 0; --i)
                currentBody = createLambda(vars[i], currentBody);

            currentBody->setSibling(node->sibling);
            return currentBody;
        }
    }

    return node;
}

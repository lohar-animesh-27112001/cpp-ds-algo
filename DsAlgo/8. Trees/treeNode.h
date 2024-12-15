#ifndef HEADER_TREE_NODE
#define HEADER_TREE_NODE

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

#endif
#pragma once
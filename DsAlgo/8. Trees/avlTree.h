#ifndef HEADER_AVL_TREE
#define HEADER_AVL_TREE

#include <bits/stdc++.h>
#include "treeNode.h"
#include "queueArray.h"

using namespace std;

class AVLTree {
private:
    TreeNode* root;

public:
    AVLTree() : root(nullptr) {
        cout << "AVL Tree constructor called !!" << endl;
    }

    TreeNode* getRoot() {
        if(root != NULL) cout << "Root of the tree is: " << root->data << endl;
        else cout << "There is no node in the AVL Tree !!" << endl;
        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* searchNode(int value) {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return nullptr;
        }
        TreeNode* node = root;
        while (node != nullptr) {
            if (value < node->data) node = node->left;
            else if (value > node->data) node = node->right;
            else return node;
        }
        cout << value << " is not present in the Tree!" << endl;
        return nullptr;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void traverse() {
        cout << "Traversal options:\n"
             << "  pre - Preorder\n"
             << "  post - Postorder\n"
             << "  in - Inorder\n"
             << "  level - Level order\n"
             << "  break - Exit traversal\n";

        string option;
        while (true) {
            cout << "Enter your choice: ";
            cin >> option;
            if (option == "in") {
                cout << "[";
                inorder(root);
                cout << "]" << endl;
            } else if (option == "pre") {
                cout << "[";
                preorder(root);
                cout << "]" << endl;
            } else if (option == "post") {
                cout << "[";
                postorder(root);
                cout << "]" << endl;
            } else if (option == "level") {
                levelorder();
            } else if (option == "break") {
                break;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }

    void deleteTree() {
        deleteTree(root);
        cout << "AVL Tree deleted successfully !!" << endl;
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int getBalance(TreeNode* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode* rightRotate(TreeNode* node) {
        TreeNode* leftChild = node->left;
        TreeNode* leftRightChild = leftChild->right;
        leftChild->right = node;
        node->left = leftRightChild;
        return leftChild;
    }

    TreeNode* leftRotate(TreeNode* node) {
        TreeNode* rightChild = node->right;
        TreeNode* rightLeftChild = rightChild->left;
        rightChild->left = node;
        node->right = rightLeftChild;
        return rightChild;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);
        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        else return node;

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data) return rightRotate(node);
        if (balance < -1 && value > node->right->data) return leftRotate(node);
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* getSwapNode(TreeNode* node) {
        TreeNode* current = node->right;
        while (current->left != nullptr) current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            cout << value << " element is not present in the AVL Tree !!" << endl;
            return nullptr;
        }
        if (value < node->data) node->left = deleteNode(node->left, value);
        else if (value > node->data) node->right = deleteNode(node->right, value);
        else {
            if (node->left == nullptr) {
                TreeNode* rightNode = node->right;
                delete node;
                return rightNode;
            } else if (node->right == nullptr) {
                TreeNode* leftNode = node->left;
                delete node;
                return leftNode;
            } else {
                TreeNode* successor = getSwapNode(node);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }

        if (node == nullptr) return nullptr;

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
        if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << ", ";
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << ", ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << ", ";
        }
    }

    void levelorder() {
        if (root == nullptr) {
            cout << "[]" << endl;
            return;
        }
        QueueArray* queue = new QueueArray();
        queue->enqueue(root->data);
        cout << "[";
        while (!queue->isEmpty()) {
            TreeNode* node = searchNode(queue->peek());
            queue->dequeue();
            cout << node->data << ", ";
            if (node->left != nullptr) queue->enqueue(node->left->data);
            if (node->right != nullptr) queue->enqueue(node->right->data);
        }
        cout << "]" << endl;
        delete queue;
    }

    void deleteTree(TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

#endif
#pragma once
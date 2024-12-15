#ifndef HEADER_BINARY_SEARCH_TREE
#define HEADER_BINARY_SEARCH_TREE

#include <bits/stdc++.h>
#include "treeNode.h"
#include "queueArray.h"

using namespace std;

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() {
        cout << "BinarySearchTree constructor called!" << endl;
        root = nullptr;
    }

    TreeNode* getRoot() {
        return root;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
            cout << value << " inserted successfully at the root!" << endl;
            return;
        }
        TreeNode* temp = root;
        while (true) {
            if (value < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = new TreeNode(value);
                    cout << value << " inserted successfully!" << endl;
                    return;
                }
                temp = temp->left;
            } else if (value > temp->data) {
                if (temp->right == nullptr) {
                    temp->right = new TreeNode(value);
                    cout << value << " inserted successfully!" << endl;
                    return;
                }
                temp = temp->right;
            } else {
                cout << value << " is already present in the Tree!" << endl;
                return;
            }
        }
    }

    void deleteNode(int value) {
        if (root == nullptr) {
            cout << "Tree is empty, nothing to delete!" << endl;
            return;
        }
        bool found = false;
        root = deleteNode(root, value, found);
        if (!found) {
            cout << value << " does not exist in the Tree!" << endl;
        } else {
            cout << value << " deleted successfully!" << endl;
        }
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
            else return node; // Node found
        }
        cout << value << " is not present in the Tree!" << endl;
        return nullptr;
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
        root = nullptr;
        cout << "Tree deleted successfully!" << endl;
    }

private:
    TreeNode* deleteNode(TreeNode* node, int value, bool& found) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = deleteNode(node->left, value, found);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value, found);
        } else {
            found = true;
            if (node->left == nullptr) {
                TreeNode* rightNode = node->right;
                delete node;
                return rightNode;
            }
            if (node->right == nullptr) {
                TreeNode* leftNode = node->left;
                delete node;
                return leftNode;
            }

            TreeNode* succ = getSuccessor(node);
            node->data = succ->data;
            node->right = deleteNode(node->right, succ->data, found);
        }
        return node;
    }

    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* curr = node->right;
        while (curr != nullptr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
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
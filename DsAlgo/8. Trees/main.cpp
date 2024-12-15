#include <bits/stdc++.h>
#include "binarySearchTree.h"
#include "avlTree.h"

using namespace std;

int main() {
    // Binary Search Tree:
    cout << "BinarySearchTree ongoing... !!!" << endl;
    BinarySearchTree* bst = new BinarySearchTree();
    bst->getRoot();
    bst->insert(23);
    bst->insert(15);
    bst->insert(50);
    bst->insert(19);
    bst->insert(10);
    bst->insert(48);
    bst->insert(52);
    bst->getRoot();
    bst->traverse();
    bst->deleteNode(123);
    bst->deleteNode(23);
    bst->getRoot();
    bst->traverse();
    bst->deleteTree();
    delete bst;

    cout << "==================================================================" << endl;

    // AVL Tree:
    cout << "AVL Tree is running:" << endl;
    AVLTree* avl = new AVLTree();
    avl->insert(12);
    avl->insert(10);
    avl->insert(100);
    avl->insert(21);
    avl->insert(20);
    avl->insert(29);
    avl->insert(15);
    avl->traverse();
    avl->getRoot();
    avl->deleteNode(avl->getRoot()->data);
    avl->traverse();
    avl->deleteTree();
    delete avl;
    return 0;
}
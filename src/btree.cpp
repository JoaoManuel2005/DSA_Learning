#include "btree.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(int value) {
    insert(root, value);
}

void BinaryTree::insert(btree_node*& node, int value) {
    if (node == nullptr) {
        node = new btree_node(value);
    } 
    else if (value < node->getValue()) {
        insert(node->getLeft(), value);
    }
    else {
        insert(node->getRight(), value);
    }
}

bool BinaryTree::search(int value) {
    return search(root, value);
}

bool BinaryTree::search(btree_node* node, int value) {
    if (node == nullptr) {
        return false;
    }
    else if (value < node->getValue()) {
        return search(node->getLeft(), value);
    }
    else if (value > node->getValue()) {
        return search(node->getRight(), value);
    }
    else {
        return true;
    }
}

void BinaryTree::inorderTraversal() const {
    inorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::preorderTraversal() const {
    preorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::postorderTraversal() const {
    postorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::inorderTraversal(btree_node* node) const {
    if (node) {
        inorderTraversal(node->getLeft());
        std::cout << node->getValue() << " ";
        inorderTraversal(node->getRight());
    }
}

void BinaryTree::preorderTraversal(btree_node* node) const {
    if (node) {
        std::cout << node->getValue() << " ";
        inorderTraversal(node->getLeft());
        inorderTraversal(node->getRight());
    }
}

void BinaryTree::postorderTraversal(btree_node* node) const {
    if (node) {
        inorderTraversal(node->getLeft());
        inorderTraversal(node->getRight());
        std::cout << node->getValue() << " ";
    }
}

btree_node*& BinaryTree::findMinNode() {
    return findMinNode(root);
}

btree_node*& BinaryTree::findMinNode(btree_node*& node) {
    btree_node** current = &node;
    while ((*current)->getLeft() != nullptr) {
        current = &((*current)->getLeft());
    }
    return *current;
}

void BinaryTree::remove(int value) {
    remove(root, value);
}

btree_node*& BinaryTree::remove(btree_node*& node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value > node->getValue()) {
        node->setRight(remove(node->getRight(), value));
    }
    else if (value < node->getValue()) {
        node->setLeft(remove(node->getLeft(), value));
    }
    else {
        if (node->getLeft() == nullptr) {
            return node->getRight();
        }
        else if (node->getRight() == nullptr) {
            return node->getLeft();
        }
        else {
            btree_node* minNode = findMinNode(node->getRight());
            node->setValue(minNode->getValue());
            node->setRight(remove(node->getRight(), minNode->getValue()));
        }
    }
    return node;
}



#include "btree.h"
#include <iostream>
#include "queue.h"

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
        preorderTraversal(node->getLeft());
        preorderTraversal(node->getRight());
    }
}

void BinaryTree::postorderTraversal(btree_node* node) const {
    if (node) {
        postorderTraversal(node->getLeft());
        postorderTraversal(node->getRight());
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

void BinaryTree::bfs() {
    bfs(&root);
}

void BinaryTree::bfs(btree_node** node){
    Queue<btree_node**> queue;
    btree_node** current;
    if (*node != nullptr) {
        queue.enqueue(node);
    }
    int level = 0;
    while (!queue.is_empty()) {
        int level_size = queue.get_length();
        std::cout << "level: " << level << std::endl;
        for (int i=0; i < level_size; i++) {
            current = queue.dequeue();
            std::cout << (*current)->getValue() << std::endl;
            if ((*current)->getLeft() != nullptr) {
                queue.enqueue((&(*current)->getLeft()));
            }
            if ((*current)->getRight() != nullptr) {
                queue.enqueue(&((*current)->getRight()));
            }
        }
        level += 1;
    }
}
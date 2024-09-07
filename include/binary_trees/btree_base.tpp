#include "btree_base.hpp"

/**
 * Constructor for binary trees
 * Sets tree root, which is a pointer to a binary tree node, to a null pointer
*/
template <typename T>
BinaryTreeBase<T>::BinaryTreeBase() : root(nullptr) {}

template <typename T>
void BinaryTreeBase<T>::inorderTraversal() const {
    inorderTraversal(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTreeBase<T>::preorderTraversal() const {
    preorderTraversal(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTreeBase<T>::postorderTraversal() const {
    postorderTraversal(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTreeBase<T>::inorderTraversal(btree_node<T>* node) const {
    if (node) {
        inorderTraversal(node->getLeft());
        printNode(node);
        inorderTraversal(node->getRight());
    }
}

template <typename T>
void BinaryTreeBase<T>::preorderTraversal(btree_node<T>* node) const {
    if (node) {
        printNode(node);
        preorderTraversal(node->getLeft());
        preorderTraversal(node->getRight());
    }
}

template <typename T>
void BinaryTreeBase<T>::postorderTraversal(btree_node<T>* node) const {
    if (node) {
        postorderTraversal(node->getLeft());
        postorderTraversal(node->getRight());
        printNode(node);
    }
}

template <typename T> 
void BinaryTreeBase<T>::printNode(const btree_node<T>* node) const {
    std::cout << node->getValue() << " ";
}
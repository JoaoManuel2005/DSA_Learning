#include "btree_node.hpp"

/**
 * Constructor for binary tree node
 * Assigns each node a value, a pointer to its right child and a pointer to its left child
*/
template <typename T>
btree_node<T>::btree_node(T value, btree_node<T>* left, btree_node<T>* right) 
    : value(value), left(left), right(right) {}

/**
 * Setter for binary tree node's left child
*/
template <typename T>
void btree_node<T>::setLeft(btree_node<T>* node) {
    left = node;
}

/**
 * Setter for binary tree node's right child
*/
template <typename T>
void btree_node<T>::setRight(btree_node<T>* node) {
    right = node;
}

/**
 * Getter for binary tree node's left child
*/
template <typename T>
btree_node<T>*& btree_node<T>::getLeft() {
    return left;
}

/**
 * Getter for binary tree node's right child
*/
template <typename T>
btree_node<T>*& btree_node<T>::getRight() {
    return right;
}

/**
 * Getter for binary tree node's value
*/
template <typename T>
T btree_node<T>::getValue() const {
    return value;
}

/**
 * Setter for binary tree node's value
*/
template <typename T>
void btree_node<T>::setValue(int val) {
    value = val;
}
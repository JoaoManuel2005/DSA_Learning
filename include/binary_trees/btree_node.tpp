#include "btree_node.hpp"

template <typename T>
btree_node<T>::btree_node(T value, btree_node<T>* left, btree_node<T>* right) 
    : value(value), left(left), right(right) {}

template <typename T>
void btree_node<T>::setLeft(btree_node<T>* node) {
    left = node;
}

template <typename T>
void btree_node<T>::setRight(btree_node<T>* node) {
    right = node;
}

template <typename T>
btree_node<T>*& btree_node<T>::getLeft() {
    return left;
}

template <typename T>
btree_node<T>*& btree_node<T>::getRight() {
    return right;
}

template <typename T>
T btree_node<T>::getValue() const {
    return value;
}

template <typename T>
void btree_node<T>::setValue(int val) {
    value = val;
}
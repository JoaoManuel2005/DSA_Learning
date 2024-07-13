#include "btree_node.h"

btree_node::btree_node(int value, btree_node* left, btree_node* right) {
    this->value = value;
    this->left = left;
    this->right = right;
}

void btree_node::setLeft(btree_node* node) {
    left = node;
}

void btree_node::setRight(btree_node* node) {
    right = node;
}

btree_node*& btree_node::getLeft() {
    return left;
}

btree_node*& btree_node::getRight() {
    return right;
}

int btree_node::getValue() const {
    return value;
}

void btree_node::setValue(int val) {
    value = val;
}
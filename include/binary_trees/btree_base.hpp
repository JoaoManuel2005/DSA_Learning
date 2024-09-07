#ifndef BINARY_TREE_BASE_H
#define BINARY_TREE_BASE_H

#include "btree_node.hpp"
#include <iostream>
#include "queue.hpp"

/**
 * Base class for binary trees
 * Used for binary search trees, binary tree maps and binary tree sets
*/
template <typename T>
class BinaryTreeBase {

    protected:
        btree_node<T>* root;

    public:
        BinaryTreeBase();
        void bfs();
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;

    protected: 
        void inorderTraversal(btree_node<T>* node) const;
        void preorderTraversal(btree_node<T>* node) const;
        void postorderTraversal(btree_node<T>* node) const;
        virtual void printNode(const btree_node<T>* node) const;

};

#include "btree_base.tpp"

#endif // BINARY_TREE_BASE_H
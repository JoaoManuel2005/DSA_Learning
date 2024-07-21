#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "btree_node.h"

class BinaryTree {
    public: 
        BinaryTree();
        void insert(int value);
        bool search(int value);
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;
        btree_node*& findMinNode();
        void remove(int value);
        void bfs();
    private:
        btree_node* root;
        void insert(btree_node*& node, int value);
        bool search(btree_node* node, int value);
        void inorderTraversal(btree_node* node) const;
        void preorderTraversal(btree_node* node) const;
        void postorderTraversal(btree_node* node) const;
        btree_node*& findMinNode(btree_node*& node);
        btree_node*& remove(btree_node*& node, int value);
        void bfs(btree_node** node);

};

#endif // BINARY_TREE_H
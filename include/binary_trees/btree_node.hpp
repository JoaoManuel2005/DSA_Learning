#ifndef BTREE_NODE_H
#define BTREE_NODE_H

template <typename T>
class btree_node {
    public:
        btree_node(T value, btree_node* left=nullptr, btree_node* right=nullptr);
        void setLeft(btree_node* node);
        void setRight(btree_node* node);
        btree_node*& getLeft();
        btree_node*& getRight();
        T getValue() const;
        void setValue(int val);
    private:
        T value;
        btree_node* left;
        btree_node* right;
};

#include "btree_node.tpp"

#endif // BTREE_NODE_H

// for special case of btree_map, T is a mapping of other T -> U
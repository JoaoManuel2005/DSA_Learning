#ifndef BTREE_SET_H
#define BTREE_SET_H

#include "btree.hpp"

template <typename T> 
class btree_set {
    public: 
        btree_set();
        void add(T value);
        bool search(T value);
    private: 
        BinaryTree<T> tree;
};

#include "btree.tpp"

#endif // BTREE_SET_H
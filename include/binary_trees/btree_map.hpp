#ifndef BTREE_MAP_H
#define BTREE_MAP_H

#include "btree.hpp"
#include "mapping.hpp"

template <typename T, typename U>
class btree_map {
    public:
        btree_map();
        void insert(mapping<T, U> pair);
        void inorderTraversal() const;
        // U search(T key);
    private:
        BinaryTree<mapping<T, U>> map;
};

#include "btree_map.tpp"

#endif // BTREE_MAP_H


// creates a binary tree who's nodes are mappings which map T to U
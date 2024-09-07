#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "btree_base.hpp"
#include "btree_node.hpp"
#include "mapping.hpp"

template <typename T, typename U = void>
class BinaryTree : public BinaryTreeBase<T> {
    public: 
        BinaryTree();
        void insert(T value);
        bool search(T value);
        btree_node<T>*& getter(T value);
        btree_node<T>*& findMinNode();
        void remove(T value);
        void bfs();
    private:
        void insert(btree_node<T>*& node, T value);
        bool search(btree_node<T>* node, T value);
        btree_node<T>*& getter(btree_node<T>* node, T value);
        btree_node<T>*& findMinNode(btree_node<T>*& node);
        btree_node<T>*& remove(btree_node<T>*& node, T value);
        void bfs(btree_node<T>** node);
};

//specialised template for creating binary trees with nodes that are mappings of T -> U
template <typename T, typename U>
class BinaryTree<mapping<T, U>> : public BinaryTreeBase<mapping<T,U>> {
    public:
        BinaryTree();
        void insert(mapping<T, U> pair);
        bool search(T key);
    protected: 
        void printNode(const btree_node<mapping<T,U>>* node) const override;
    private: 
        void insert(btree_node<mapping<T, U>>*& node, mapping<T, U> pair);
        bool search(btree_node<mapping<T, U>>* node, T key);
};

extern template class BinaryTree<mapping<char, int>>;

#include "btree.tpp"

#endif // BINARY_TREE_H
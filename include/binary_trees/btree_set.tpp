#include "btree_set.hpp"

template <typename T>
btree_set<T>::btree_set() {}

template <typename T>
void btree_set<T>::add(T value) {
    tree.insert(value);
}

template <typename T>
bool btree_set<T>::search(T value) {
    tree.inorderTraversal();
    return tree.search(value);
}



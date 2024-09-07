#include "btree_map.hpp"

template <typename T, typename U>
btree_map<T, U>::btree_map() {}

template <typename T, typename U>
void btree_map<T,U>::insert(mapping<T, U> pair) {
    map.insert(pair);
}

template <typename T, typename U>
void btree_map<T,U>::inorderTraversal() const {
    map.inorderTraversal();
}

// template <typename T, typename U>
// U btree_map<T, U>::search(T key) {
//     btree_node<T>* node = map.getter(key);
//     U value = *node.getValue();
//     return value;
// }
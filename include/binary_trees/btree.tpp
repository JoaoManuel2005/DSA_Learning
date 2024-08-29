#include "btree.hpp"
#include <iostream>
#include "queue.hpp"
#include "mapping.hpp"

template <typename T, typename U>
BinaryTree<T, U>::BinaryTree() : BinaryTreeBase<T>() {}

template <typename T, typename U>
void BinaryTree<T, U>::insert(T value) {
    insert(this->root, value);
}

template <typename T, typename U>
void BinaryTree<T, U>::insert(btree_node<T>*& node, T value) {
    if (node == nullptr) {
        node = new btree_node<T>(value);
    } 
    else if (value < node->getValue()) {
        insert(node->getLeft(), value);
    }
    else {
        insert(node->getRight(), value);
    }
}

template <typename T, typename U>
bool BinaryTree<T, U>::search(T value) {
    return search(this->root, value);
}

template <typename T, typename U>
bool BinaryTree<T, U>::search(btree_node<T>* node, T value) {
    if (node == nullptr) {
        return false;
    }
    else if (value < node->getValue()) {
        return search(node->getLeft(), value);
    }
    else if (value > node->getValue()) {
        return search(node->getRight(), value);
    }
    else {
        return true;
    }
}

template <typename T, typename U>
btree_node<T>*& BinaryTree<T, U>::getter(T value) {
    return getter(this->root, value);
}

template <typename T, typename U>
btree_node<T>*& BinaryTree<T, U>::getter(btree_node<T>* node, T value) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (value < node->getValue()) {
        return getter(node->getLeft(), value);
    }
    else if (value > node->getValue()) {
        return getter(node->getRight(), value);
    }
    else {
        return node;
    }    
}

template <typename T, typename U>
btree_node<T>*& BinaryTree<T, U>::findMinNode() {
    return findMinNode(this->root);
}

template <typename T, typename U>
btree_node<T>*& BinaryTree<T, U>::findMinNode(btree_node<T>*& node) {
    btree_node<T>** current = &node;
    while ((*current)->getLeft() != nullptr) {
        current = &((*current)->getLeft());
    }
    return *current;
}

template <typename T, typename U>
void BinaryTree<T, U>::remove(T value) {
    remove(this->root, value);
}

template <typename T, typename U>
btree_node<T>*& BinaryTree<T, U>::remove(btree_node<T>*& node, T value) {
    if (node == nullptr) {
        return node;
    }

    if (value > node->getValue()) {
        node->setRight(remove(node->getRight(), value));
    }
    else if (value < node->getValue()) {
        node->setLeft(remove(node->getLeft(), value));
    }
    else {
        if (node->getLeft() == nullptr) {
            return node->getRight();
        }
        else if (node->getRight() == nullptr) {
            return node->getLeft();
        }
        else {
            btree_node<T>* minNode = findMinNode(node->getRight());
            node->setValue(minNode->getValue());
            node->setRight(remove(node->getRight(), minNode->getValue()));
        }
    }
    return node;
}

template <typename T, typename U>
void BinaryTree<T, U>::bfs() {
    bfs(&this->root);
}

template <typename T, typename U>
void BinaryTree<T, U>::bfs(btree_node<T>** node){
    Queue<btree_node<T>**> queue;
    btree_node<T>** current;
    if (*node != nullptr) {
        queue.enqueue(node);
    }
    int level = 0;
    while (!queue.is_empty()) {
        int level_size = queue.get_length();
        std::cout << "level: " << level << std::endl;
        for (int i=0; i < level_size; i++) {
            current = queue.dequeue();
            if (current == nullptr || *current == nullptr) {
                continue;
            }
            std::cout << (*current)->getValue() << std::endl;
            if ((*current)->getLeft() != nullptr) {
                queue.enqueue((&(*current)->getLeft()));
                std::cout << "Enqueued left child with value: " << (*current)->getLeft()->getValue() << std::endl;
            }
            if ((*current)->getRight() != nullptr) {
                queue.enqueue(&((*current)->getRight()));
                std::cout << "Enqueued right child with value: " << (*current)->getRight()->getValue() << std::endl;
            }
        }
        level += 1;
    }
}


// implementation of specifalised template to handle tree nodes that are mapping<T, U>
template <typename T, typename U>
BinaryTree<mapping<T, U>>::BinaryTree() : BinaryTreeBase<mapping<T, U>>() {}

template <typename T, typename U>
void BinaryTree<mapping<T, U>>::insert(mapping<T, U> pair) {
    insert(this->root, pair);
}

template <typename T, typename U>
void BinaryTree<mapping<T, U>>::insert(btree_node<mapping<T, U>>*& node, mapping<T, U> pair) {
    if (node == nullptr) {
        node = new btree_node<mapping<T,U>>(pair);
    }
    else if (pair.getKey() < node->getValue().getKey()) {
        insert(node->getLeft(), pair);
    }
    else {
        insert(node->getRight(), pair);
    }
}

template <typename T, typename U>
bool BinaryTree<mapping<T, U>>::search(T key) {
    return search(this->root, key);
}

template <typename T, typename U>
bool BinaryTree<mapping<T, U>>::search(btree_node<mapping<T, U>>* node, T key) {
    if (node == nullptr) {
        return false;
    } else if (key < node->value.getKey()) {
        return search(node->left, key);
    } else if (key > node->value.getKey()) {
        return search(node->right, key);
    } else {
        return true;
    }
}

template <typename T, typename U>
void BinaryTree<mapping<T, U>>::printNode(const btree_node<mapping<T, U>>* node) const {
    std::cout << node->getValue().getKey() << " ";
}
#include "btree.hpp"
#include <iostream>
#include "queue.hpp"
#include "mapping.hpp"

/**
 * Constructor for binary search tree
 * Calls base binary tree constructor
*/
template <typename T, typename U>
BinaryTree<T, U>::BinaryTree() : BinaryTreeBase<T>() {}

/**
 * Function to insert nodes in binary tree
 * Recursively travels down binary tree from root to find where new node belongs
 * @param value object to be stored as value of node that is being added
*/
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

/**
 * Function to search for values in binary search tree
 * Recursively travels down binary tree from root to find value
 * @param value the value we are looking for
*/
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

/**
 * Getter for binary search tree nodes
 * Recursively travels down binary tree from root to find node with value we want to get
 * @param value the value stored in the node we want to get
 * @return node 
*/
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

/**
 * Getter for binary trees node with smallest value
 * Starts from root and goes down always following the left child pointer to reach smallest valued node
 * @return node
*/
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

/**
 * Function to remove node from binary tree
 * First recursively finds node we want to remove based on value parameter passed to function
 * then once found, handles three cases:
 *
 * 1. Node has no children or one child:
 *    - If the node has no children (leaf node) it is removed by connecting its parent directly to nullptr
 * 
 * 2. Node has only one child (either left or right),
 *    - Node is removed by connecting its parent directly to its single child 
 * 
 * 3. Node has two children:
 *    - If the node to be removed has two children, the function finds the minimum node
 *      in the right subtree (in-order successor), replaces the current node's value
 *      with the in-order successor's value, and then recursively deletes the in-order
 *      successor node.
 */
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

/**
 * Function to traverse through binary tree using breadth-first search
 * It explores all nodes at the present depth before moving on to nodes at the next level,
 * uses a queue to store the nodes to be visited
*/
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


/**
 * Implementation of specifalised template to handle tree nodes that are mapping<T, U>
 * Allows us to create a binary tree map
 */
template <typename T, typename U>
BinaryTree<mapping<T, U>>::BinaryTree() : BinaryTreeBase<mapping<T, U>>() {}

/**
 * Function to insert new mapping node to binary tree
 * Uses same logic of recursively searching for where node belongs in tree 
 * but uses as the mappings key to make the comparisons instead
*/
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

/**
 * Function to search for mapping in binary tree
 * Uses same logic of recursively searching for where node is in tree 
 * but uses as the mappings key to make the comparisons instead
*/
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
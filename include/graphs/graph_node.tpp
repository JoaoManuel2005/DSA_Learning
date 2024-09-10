#include "graph_node.hpp"

template <typename T>
graphNode<T>::graphNode(T value) : m_value(value), m_neighbours() {}

template <typename T>
T graphNode<T>::getValue() {
    return m_value;
}

template <typename T>
singly_linked_list<graphNode<T>*> graphNode<T>::getNeighbours() {
    return m_neighbours;
}

template <typename T>
void graphNode<T>::setValue(T value) {
    m_value = value;
}

template <typename T>
void graphNode<T>::setNeighbours(singly_linked_list<graphNode<T>*> neighbours) {
    node<T>* current = neighbours.get_header_node();
    while (current != nullptr) {
        m_neighbours.push(current->getValue());
        current = current->getNext();
    }
}
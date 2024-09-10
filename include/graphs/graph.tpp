#include "graph.hpp"
#include <iostream>
#include <string>

template <typename T>
Graph<T>::Graph() : m_directed(false), m_V(0) {}

template <typename T>
Graph<T>::Graph(bool directed) : m_directed(directed), m_V(0) {}

template <typename T>
void Graph<T>::addNode(T value) {
    if (!adjList.search(value)) {
        graphNode<T>* node = new graphNode<T>(value);
        adjList.put(mapping<T, graphNode<T>*>(value, node));
        m_V++;
    }
}

template <typename T>
void Graph<T>::add_edge(T U, T V) {
    if (!adjList.search(U)) {
        addNode(U);
    }
    if (!adjList.search(V)) {
        addNode(V);
    }
    graphNode<T>* node = adjList.getValue(U);
    singly_linked_list<graphNode<T>*> neighbours = node->getNeighbours();
    neighbours.push(adjList.getValue(V));

    if (!m_directed) {
        graphNode<T>* V_node = adjList.getValue(V);
        singly_linked_list<graphNode<T>*> V_neighbours = V_node->getNeighbours();
        V_neighbours.push(node); 
    }
}

template <typename T>
graphNode<T>* Graph<T>::getNode(T value) {
    if (adjList.search(value)) {
        return adjList.getValue(value);
    }
    return nullptr;
}

template <typename T>
void Graph<T>::printGraph() {
    int capacity = adjList.getCapacity();
    singly_linked_list<mapping<T, graphNode<T>*>>* array = adjList.getArrayPointer();
    for (int i = 0; i < capacity; i++) {
        std::cout << "Vertex " << array[i].get_header_node()->getValue().getValue()->getValue() << std::endl;
        singly_linked_list<graphNode<T>*> neighbours = array[i].get_header_node()->getValue().getValue()->getNeighbours();
        node<graphNode<T>*>* current = neighbours.get_header_node();
        std::cout << "Neighbours " << std::endl;
        while (current != nullptr) {
            std::cout << current->getValue()->getValue() << std::endl;
        }
        
    }
}
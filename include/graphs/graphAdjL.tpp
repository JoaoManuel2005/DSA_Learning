#include "graphAdjL.hpp"
#include <iostream>

/**
 * Constructor for graph
 * If we don't specify if graph is directed, it means it's not
*/
template <typename T>
GraphAdj<T>::GraphAdj() : m_directed(false), m_V(0) {}

/**
 * Constructor for graph with boolean option for wheter graph is directed or not
*/
template <typename T>
GraphAdj<T>::GraphAdj(bool directed) : m_directed(directed), m_V(0) {}


template <typename T>
void GraphAdj<T>::addNode(T value) {
    if (!m_adjList.search(value)) {
        singly_linked_list<edge<T>> list;
        m_adjList.put(mapping<T,singly_linked_list<edge<T>>>(value, list));
        m_V++;
    }
}

template <typename T>
void GraphAdj<T>::add_edge(T U, T V) {
    if (!m_adjList.search(U)) {
        addNode(U);
    }
    if (!m_adjList.search(V)) {
        addNode(V);
    }

    edge<T> directed_edge;
    directed_edge.nodes[0] = U;
    directed_edge.nodes[1] = V;

    singly_linked_list<edge<T>> edges = m_adjList.getValue(U);
    edges.push(directed_edge);

    if (!m_directed) {
        edge<T> undirected_edge;
        undirected_edge.nodes[0] = V;
        undirected_edge.nodes[1] = U;

        singly_linked_list<edge<T>> edges = m_adjList.getValue(V);
        edges.push(undirected_edge);
    }
}

template <typename T>
mapping<T, singly_linked_list<edge<T>>> GraphAdj<T>::getNode(T value) {
    return mapping<T, singly_linked_list<edge<T>>>(value, m_adjList.getValue(value));
}

template <typename T>
void GraphAdj<T>::printGraph() {
    for (auto it = m_adjList.begin(); it != m_adjList.end(); ++it) {
        singly_linked_list<mapping<T, singly_linked_list<edge<T>>>>& list = *it;
        mapping<T, singly_linked_list<edge<T>>> map = list.get_header_node();
        T vertex = map.getKey();
        std::cout << "Vertex: " << vertex << std::endl;
        std::cout << "Neighbours: " << std::endl;
        

    }
}

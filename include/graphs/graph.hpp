#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../chain_hash.hpp"
#include "../linked_lists/single_linked_list.hpp"
#include "graph_node.hpp"

template <typename T>
class Graph {

    public:
        Graph();
        Graph(bool directed);
        void addNode(T value);
        void add_edge(T U, T V);
        graphNode<T>* getNode(T value);
        void printGraph();

    private:
        bool m_directed;
        chainHash<T, graphNode<T>*> adjList;
        int m_V;

};

#include "graph.tpp"

#endif // GRAPH_HPP
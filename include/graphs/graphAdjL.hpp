#ifndef GRAPHADJL_HPP
#define GRAPHADJL_HPP

#include "edge.hpp"
#include "graph_node.hpp"
#include "../chain_hash.hpp"
#include "../linked_lists/single_linked_list.hpp"

/**
 * Adjacency list implementation of graph
 * Graph is a hashmap which stores mappings of graph node values and graph node edges
 * Edge data structure defined in edge.hpp
*/
template <typename T>
class GraphAdj {

    private:
        bool m_directed;
        chainHash<T, singly_linked_list<edge<T>>> m_adjList;
        int m_V;

    public:
        GraphAdj();
        GraphAdj(bool directed);
        void addNode(T value);
        void add_edge(T U, T V);
        mapping<T, singly_linked_list<edge<T>>> getNode(T value);
        void printGraph();

};

#include "graphAdjL.tpp"

#endif // GRAPHADJL_HPP
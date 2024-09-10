#ifndef GRAPHADJL_HPP
#define GRAPHADJL_HPP

#include "edge.hpp"
#include "graph_node.hpp"
#include "../chain_hash.hpp"
#include "../linked_lists/single_linked_list.hpp"

template <typename T>
class GraphAdj {

    public:
        GraphAdj();
        GraphAdj(bool directed);
        void addNode(T value);
        void add_edge(T U, T V);
        mapping<T, singly_linked_list<edge<T>>> getNode(T value);
        void printGraph();

    private:
        bool m_directed;
        chainHash<T, singly_linked_list<edge<T>>> m_adjList;
        int m_V;

};

#include "graphAdjL.tpp"

#endif // GRAPHADJL_HPP
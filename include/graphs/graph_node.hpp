#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP

#include "linked_lists/single_linked_list.hpp"

template <typename T>
class graphNode {

    public:
        graphNode(T value);
        T getValue();
        singly_linked_list<graphNode*> getNeighbours();
        void setValue(T value);
        void setNeighbours(singly_linked_list<graphNode*> neighbours);

    private:
        T m_value;
        singly_linked_list<graphNode*> m_neighbours;

};

#include "graph_node.tpp"

#endif // GRAPH_NODE_HPP
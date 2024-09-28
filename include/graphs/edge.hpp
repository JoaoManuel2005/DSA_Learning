#ifndef EDGE_HPP
#define EDGE_HPP

/**
 * Edge data structure
 * Each node in a graph has its corresponding edges, 
 * an array of values T corresponding to the values of the nodes it is neighbours with 
*/
template <typename T>
struct edge {
    T nodes[2];
    float cost; // add more if you need it
};

#endif // EDGE_HPP
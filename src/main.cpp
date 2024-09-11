#include <iostream>
#include <linked_lists/single_linked_list.hpp>
#include <linked_lists/double_linked_list.hpp>
#include <chain_hash.hpp>
//#include <graphs/graph.hpp>

int main() {

// 
//             TESTING LINKED LISTS
//

    doubly_linked_list<int> list;
    list.push(2);
    list.push(4);
    list.push(2);
    list.push(4);
    list.remove(2);
    list.insert(9, 2);
    list.print_list();
    // Forward iteration
    std::cout << "Forward iteration: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Backward iteration (starting from the last element)
    std::cout << "Backward iteration: ";
    auto it = list.end();  // `it` is now pointing to the "end" node (nullptr)
    if (it != list.begin()) {
        --it;  // Move the iterator back to the last element
        while (it != list.begin()) {
            std::cout << *it << " ";
            --it;
        }
        // Print the first element as the loop ends before it
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Now single linked list:" << std::endl;
    singly_linked_list<int> s_list;
    s_list.push(2);
    s_list.push(4);
    s_list.push(2);
    s_list.push(4);
    s_list.remove(2);
    s_list.insert(9, 2);
    s_list.print_list();
    for (auto it = s_list.begin(); it != s_list.end(); ++it) {
        std::cout << *it << " ";  // Dereferencing the iterator to get the value
    }
    std::cout << std::endl;

// 
//             TESTING BINARY TREES
//

    // BinaryTree<int> tree;
    // tree.insert(10);
    // tree.insert(5);
    // tree.insert(15);
    // tree.insert(3);
    // tree.insert(7);
    // tree.insert(12);
    // tree.insert(17);
    // tree.inorderTraversal();    

    // tree.remove(10);

    // tree.inorderTraversal();

    // tree.bfs();

//
//             TESTING BINARY TREE MAPS
//
//              NEEDS TO BE FIXED
//
//

    // btree_map<char, int> treee;
    // treee.insert(mapping('s', 1));
    // treee.insert(mapping('a', 3));
    // treee.insert(mapping('b', 2));
    // treee.insert(mapping('t', 5));
    // treee.inorderTraversal();
    // //treee.search('a');

//
//             TESTING CHAINING IMPLEMENTATION OF HASH MAPS
//

    // chainHash<char, int> hashMap;
    // hashMap.put(mapping<char, int>('c', 9));
    // hashMap.put(mapping<char, int>('b', 93));
    // hashMap.put(mapping<char, int>('a', 9));
    // hashMap.put(mapping<char, int>('y', 2));
    // hashMap.put(mapping<char, int>('j', 5));
    // hashMap.put(mapping<char, int>('c', 76));
    // hashMap.put(mapping<char, int>('e', 5));
    // hashMap.put(mapping<char, int>('b', 49));
    // hashMap.put(mapping<char, int>('d', 7));
    // hashMap.put(mapping<char, int>('i', 1));
    // hashMap.put(mapping<char, int>('c', 0));
    // hashMap.print();
    // std::cout << "" << std::endl;
    // hashMap.remove('b');
    // hashMap.remove('j');
    // hashMap.print();
    // std::cout << "" << std::endl;
    // std::cout << hashMap.search('c') << std::endl;
    // std::cout << hashMap.search('o') << std::endl;
    // std::cout << hashMap.getValue('c') << std::endl;
    // std::cout << hashMap.getValue('o') << std::endl;
    
//
//             TESTING GRAPHS
//

    // Graph<int> graph;
    // graph.addNode(1);
    // graph.addNode(3);
    // graph.addNode(2);
    // graph.add_edge(1,3);
    // graph.add_edge(2,3);
    // graph.add_edge(3,2);
    // graph.printGraph();

}

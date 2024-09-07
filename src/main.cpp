#include <iostream>
#include <binary_trees/btree.hpp>
#include <binary_trees/btree_map.hpp>
#include <binary_trees/btree_set.hpp>
#include <linked_lists/single_linked_list.hpp>
#include <linked_lists/double_linked_list.hpp>

int main() {

// 
//             TESTING LINKED LISTS
//

    // doubly_linked_list<int> list;
    // list.push(2);
    // list.push(4);
    // list.push(2);
    // list.push(4);
    // list.remove(2);
    // list.insert(9, 2);
    // list.print_list();
    // std::cout << "Now single linked list:" << std::endl;
    // singly_linked_list<int> s_list;
    // s_list.push(2);
    // s_list.push(4);
    // s_list.push(2);
    // s_list.push(4);
    // s_list.remove(2);
    // s_list.insert(9, 2);
    // s_list.print_list();

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

    btree_map<char, int> treee;
    treee.insert(mapping('s', 1));
    treee.insert(mapping('a', 3));
    treee.insert(mapping('b', 2));
    treee.insert(mapping('t', 5));
    treee.inorderTraversal();
    //treee.search('a');


}

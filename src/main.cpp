#include <linked_lists/single_linked_list.hpp>
#include <sorting_algorithms.hpp>
#include <search_algorithms.hpp>
#include <queue.hpp>
#include <stack.hpp>
// #include <btree.hpp>
#include <iostream>
// #include <btree_map.hpp>
#include <mapping.hpp>
#include <priority_queue.hpp>

int main() {
//     BinaryTree<int> tree;
//     tree.insert(10);
//     tree.insert(5);
//     tree.insert(15);
//     tree.insert(3);
//     tree.insert(7);
//     tree.insert(12);
//     tree.insert(17);
//     tree.inorderTraversal();    

// //   //  tree.remove(10);

// //     tree.inorderTraversal();

// //     tree.bfs();

//     btree_map<char, int> treee;
//     treee.insert(mapping('s', 1));
//     treee.insert(mapping('a', 3));
//     treee.insert(mapping('b', 2));
//     treee.insert(mapping('t', 5));
//     treee.inorderTraversal();
//     //treee.search('a');

    Priority_Q queue;
    queue.push(1);
    queue.push(4);
    queue.push(3);
    queue.push(7);
    queue.push(8);
    queue.push(2);
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    queue.push(9);
    queue.push(1);
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;


}

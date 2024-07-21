#include <linked_lists/single_linked_list.h>
#include <sorting_algorithms.h>
#include <search_algorithms.h>
#include <queue.h>
#include <stack.h>
#include <btree.h>
#include <iostream>

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    tree.inorderTraversal();    

  //  tree.remove(10);

    tree.inorderTraversal();

    tree.bfs();
}
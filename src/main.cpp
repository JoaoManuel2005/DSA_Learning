#include <linked_lists/single_linked_list.h>
#include <linked_lists/single_linked_node.h>
#include <linked_lists/double_linked_list.h>
#include <linked_lists/double_linked_node.h>
#include <sorting_algorithms.h>
#include <queue.h>
#include <stack.h>
#include <iostream>

int main() {
    std::vector<int> list = {1, 4, 2, 8, 9, 3};
    mergeSort(list, 0, list.size()-1);
    for (int i=0; i<list.size(); i++) {
        std::cout << list[i] << std::endl;
    }
}
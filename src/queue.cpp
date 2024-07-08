#include "queue.h"
#include "linked_lists/single_linked_list.h"
#include <iostream>

Queue::Queue() : q() {}

void Queue::enqueue(int value) {
    q.push(value);
}

int Queue::dequeue() {
    int result = q.get_header();
    q.remove(result);
    std::cout << result << std::endl;
    return result;
}

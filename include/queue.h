#ifndef QUEUE_H
#define QUEUE_H

#include "linked_lists/single_linked_list.h"

class Queue {
    public: 
        Queue();
        void enqueue(int value);
        int dequeue();
    private:
        singly_linked_list q;

};

#endif // QUEUE_H
#ifndef SINGLE_LINKED_H
#define SINGLE_LINKED_H

#include <vector>
#include "single_linked_node.h"

class singly_linked_list {
    public:
        void initialize();
        void push(int value);
        void head_push(int value);
        void remove(int value);
        void insert(int value, int position);
    private:
        node* header;
        node* tail;
        std::vector<node> list;
};

#endif // SINGLE_LINKED_H
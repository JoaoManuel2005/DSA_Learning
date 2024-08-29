#include "priority_queue.hpp"
#include <iostream>

Priority_Q::Priority_Q() : Q(1) {}

void Priority_Q::push(int value) {
    Q.push_back(value);
    int i = Q.size()-1;
    while (i > 1 && Q[i] < Q[PARENT(i)]) {
        int temp = Q[i];
        Q[i] = Q[PARENT(i)];
        Q[PARENT(i)] = temp;
        i = PARENT(i);
    }
    // for (int i = 0; i < Q.size(); i++) {
    //     std::cout << Q[i] << std::endl;
    // }
    // std::cout << " " << std::endl;
}

int Priority_Q::pop() {
    if (Q.size() == 1) {
        throw std::underflow_error("Priority queue is empty.");
    }

    if (Q.size() == 2) {
        int result = Q.back();
        Q.pop_back();
        return result;
    }

    int result = Q[1];
    Q[1] = Q.back();
    Q.pop_back();
    int i = 1;
    while (LEFT_CHILD(i) < Q.size()) {
        if (RIGHT_CHILD(i) < Q.size() && Q[RIGHT_CHILD(i)] < Q[LEFT_CHILD(i)] && Q[i] > Q[RIGHT_CHILD(i)]) {
            int temp = Q[i];
            Q[i] = Q[RIGHT_CHILD(i)];
            Q[RIGHT_CHILD(i)] = temp;
            i = RIGHT_CHILD(i);
        }
        else if (Q[i] > Q[LEFT_CHILD(i)]) {
            int temp = Q[i];
            Q[i] = Q[LEFT_CHILD(i)];
            Q[LEFT_CHILD(i)] = temp;
            i = LEFT_CHILD(i);
        }
        else {
            break;
        }
    }
    return result;
}
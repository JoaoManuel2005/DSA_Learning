#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

class Priority_Q {

    public:
        Priority_Q();
        void push(int value);
        int pop();
        auto heapify();

    private:
        std::vector<int> Q;
        int LEFT_CHILD(int i) {return 2*i;}
        int RIGHT_CHILD(int i) {return 2*i+1;}
        int PARENT(int i)  {return i / 2;}

};

#endif // PRIORITY_QUEUE_H
// Assignment C++: 2

#pragma once

#ifndef __MYQUEUE_H
#define __MYQUEUE_H
#include <vector>
#include "ostream"
using namespace std;
#define defaultQsize 10
#endif //__MYQUEUE_H

/**
    myQueue Class will maintain a Queue using the Class vector, it will allow the user to add and remove
    elements from the Queue using FIFO, use logical operators on the Queue
    and peek to get the value of the first element and finally print the Queue
**/

class myQueue {
    vector<int> vec;        // vector of ints that holds the elements and unique functions
    int maxQ;       // max size we allow for the Queue, given by user
public:
    myQueue();      // myQueue default Constructor
    explicit myQueue(int maxQ);     // myQueue Constructor, initialize max size of Queue to maxQ and initialize vector
    bool enQueue(int val);      // insert a new element to the queue if it isn't full
    bool deQueue();     // remove the first element in the queue if it isn't empty (FIFO)
    bool isEmpty() const;       // return true if the Queue is empty, false otherwise
    int* peek() const;      // return pointer to the first element in the Queue
    int getSize() const;        // return the current size of the elements inside the Queue
    int operator[](int n) const;       // return the value of the element in the n position of the Queue
    friend ostream& operator<<(ostream& os, const myQueue& Q);      // print the Queue, allow chaining
    ~myQueue();     // default Destructor
};
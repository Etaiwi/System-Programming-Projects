// Assignment C++: 2


#include "myQueue.h"

/** myQueue default Constructor: maximum size of the Queue is initialized to default 10 **/
myQueue::myQueue():maxQ(defaultQsize), vec() {}

/** myQueue Constructor: initialize vector and the maximum size of the Queue to maxQ **/
myQueue::myQueue(int maxQ):maxQ(maxQ), vec() {}

/** enQueue a new element val to the Queue, return true if the insertion was successful, false otherwise (Queue is full **/
bool myQueue::enQueue(int val) {
    if(vec.size() < maxQ){      // check if Q is full
        vec.push_back(val);     // if Q isn't full, push val into it and return true
        return true;
    }
    return false;       // if Q is full return false
}

/** deQueue an element using FIFO, return true if the extraction was successful, false otherwise (Queue is empty) **/
bool myQueue::deQueue() {
    if (!vec.empty()) {     // check if Q is empty
        vec.erase(vec.begin());     // if Q isn't empty, pop the first element that was inserted (FIFO) and return true
        return true;
    }
    return false;       // if Q is empty return false
}

/** isEmpty check if the Queue is empty and return true if it is empty, and false if it its not empty **/
bool myQueue::isEmpty() const {
    return vec.empty();
}

/** peek return pointer to the first element in the Queue, return nullptr if the Queue is empty **/
int* myQueue::peek() const {
    if(!vec.empty()){       // if Queue isn't empty, return the pointer to the first element, otherwise return nullptr
        return const_cast<int *>(vec.data());       // vec.data() return pointer to the array memory, which means that it points to the first element
    }
    return nullptr;
}

/** geSize return the current amount of elements in the Queue **/
int myQueue::getSize() const{
    return (int)vec.size();
}

/** [] operator: return the value of the n element in the Queue **/
int myQueue::operator[](int n) const{
    return vec.at(n);
}

/** << operator: print to the screen the Queue Q with given format **/
ostream& operator<<(ostream& os,const myQueue& Q) {
    int i;
    for (i = 0; i < Q.getSize()-1; i++)  os << Q[i] << " <- ";      // until last element, print with the given format
    os << Q[i];     // last element without pointer
    return os;
}

/** myQueue default Destructor **/
myQueue::~myQueue() = default;


// Assignment C++: 1


#include "Stack.h"

Stack::Stack() {    // Stack Constructor initiate top pointer to NULL
    this->top = nullptr;
}

void Stack::push(int new_data) {        // push new_data to a newly created cell
    StackNode *temp = top;              // holding the pointer of top to not lose it
    top = new(StackNode);               // allocating memory for the new cell that will hold the new data and top pointing to it
    top->set_data(new_data);         // initiate new node data to given new_data
    top->set_next(temp);       // set next field of new cell to the previous cell that top held
}

int Stack::pop() {  // Pop an element from the Stack, pop will not be called if Stack is empty
    int curr_data = top->get_data();    // hold the data of the cell to return it later
    StackNode* temp = top->get_next();
    delete(top);    // release the space that the cell held
    top = temp;     // updating who top points to
    return curr_data;   // return the data of the deleted element
}

bool Stack::isEmpty() const {     // return true if the Stack is empty and false if its not empty
    if(top == nullptr) return true;
    else return false;
}

int Stack::peek() const {       // return only the data that top holds without changing anything
    if (top != nullptr) {
        return this->top->get_data();   // return cell data if Stack is not empty
    }
    else return INT_MIN;    // if Stack is empty, return lower limit of int
}

Stack::~Stack() {       // Stack Destructor that release all allocated memory using pop until empty
    while(!isEmpty()) pop();    // loop runs until the Stack is empty
}
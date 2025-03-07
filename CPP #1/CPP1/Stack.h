// Assignment C++: 1

#pragma once

#include "StackNode.h"
#include "iostream"
using namespace std;
#include <climits>

/**
    Stack class is a dynamically updated stack that hold a pointer to the actual linked list that holds
    the data and pointer to the next cells.
    It has methods that simulate the actions that we can make with stack.
    It can push an element, pop an element, check if the stack is empty, and peek to obtain the data of the top element
**/

class Stack {
private:
    StackNode* top;              // pointer to the top cell
public:
    Stack();                     // Stack Constructor that initiates top to NULL
    void push(int new_data);     // Push new item to the Stack
    int pop();                   // Pop an element from the Stack, pop will not be called if the Stack is empty
    bool isEmpty() const;        // return true if the Stack is empty and false if Stack not empty
    int peek() const;            // return only the data that top holds without changing anything
    ~Stack();                    // Stack Destructor that release all allocated memory using pop until empty
};

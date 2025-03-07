// Assignment C++: 1

#pragma once

/**
    each StackNode holds the data in the given cell and a pointer to
    the next cell.
**/

class StackNode {
private:
    int data{};                             // current cell data
    StackNode *next{};                      // pointer to next cell
public:
    StackNode();                            // default Constructor
    void set_data(int d);                   // set current data to given int
    int get_data() const;                   // return data field
    void set_next(StackNode* curr_node);    // set the next field of the node to the previous node
    StackNode* get_next() const;            // return next which is a pointer to StackNode
    ~StackNode();                           // default Destructor
};
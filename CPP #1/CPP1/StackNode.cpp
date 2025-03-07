/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/

#include "StackNode.h"

StackNode::StackNode() = default;   // default Constructor

void StackNode::set_data(int d) {    // set the data field of the node to given data
    this->data = d;
}

int StackNode::get_data() const{     // return data field
    return this->data;
}

void StackNode::set_next(StackNode *curr_node) {    // set next field of the current node to the previous node
    this->next = curr_node;
}

StackNode* StackNode::get_next() const{     // return next which is a pointer to next node
    return this->next;
}

StackNode::~StackNode() = default;  // default Destructor

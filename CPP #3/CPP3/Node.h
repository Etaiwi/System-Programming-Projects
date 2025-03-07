// Assignment C++: 3


#pragma once


/** Node template class: hold the data of the shapes in each node, and pointer to the next node **/
template <class T>
class Node {
private:
    T data;     // The data stored in the node
    Node<T>* Next;      // A pointer to the next node in the linked list
public:
    /** Give friend to class LinkedList **/
    template <class V>
    friend class LinkedList;

    /** Default Constructor **/
    Node(): data(nullptr), Next(nullptr) {};

    /** Constructor : Initiate data field with given data and Next field to nullptr **/
    explicit Node(T data): data(data), Next(nullptr) {};

    /** Default Destructor **/
    ~Node() = default;
};
// Assignment C++: 3


#pragma once

#include "Node.h"
#include "ostream"
using namespace std;

/**
    LinkedList Template Class create a LinkedList that can hold various Types of Nodes, allow basic LinkedList operations
**/

template <class T>
class LinkedList {
private:
    Node<T>* head; // A pointer to the first node in the linked list.
public:
    /** Default Constructor : Create an empty linked list **/
    LinkedList() : head(nullptr) {};

    /** Insert: Create a new Node object with given data and insert in front of the linked list **/
    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);       // create a new Node for given data
        newNode->Next = head;       // new Node point to current head
        head = newNode;     // new Node becomes the new head
    };

    /** DeleteNode : Delete the first Node in the list and return the data of this Node, if list is empty, throw an exception **/
    T deleteNode() {
        if (head == nullptr) {      // if list is empty throw an exception
            throw runtime_error("List is Empty");
        }
        Node<T> *temp = head;       // save head as temp to not lose it
        T data = head->data;      // obtain the data of the soon-to-be deleted Node
        head = head->Next;        // head now points to the next Node in line
        delete temp;        // delete the Node
        return data;        // return the data of the deleted Node
    };

    /** DeleteNode(const T&) : Search the first occurrence of a Node with given Data and delete it, return the deleted Node Data **/
    T deleteNode(const T& data) {
        if (head == nullptr) {      // if list is empty throw an exception
            throw runtime_error("List doesnt have given Data Node");
        }
        if (head->data == data) return deleteNode();

        Node<T>* curr = head->Next;       // pointer to node (start at head->next)
        Node<T>* prev = head;       // pointer to previous node (start at head)
        while(curr != nullptr) {        // we exit if there is no given Data in the Linked List
            if (curr->data == data) {     // found first occurrence of data in the list
                prev->Next =curr->Next;       // set prev Next to curr Next
                T del_data = curr->data;      // obtain the data
                delete curr->data;      // delete the data in the Node
                delete curr;        // delete the Node
                return del_data;        // return the deleted node data
            }
        }
        throw runtime_error("Node with given data doesnt exist");      // we get here if given Data was not found in the Linked List
    }

    /** Search(const T&) : Search the first occurrence in the List with given Data and return true if the Node was found, false otherwise **/
    bool search(const T& data) {
        Node<T>* curr = head;       // pointer to Node (start at head)
        while (curr != nullptr) {
            if (curr->data == data) return true;      // given Data found in a Node in the List
            curr = curr->Next;        // 1 step into the Linked List
        }
        return false;       // we get here if given Data was not found in the Linked List
    }

    /** GetTop : Return the last inserted element(data) in the list, if the list is empty, throw an exception **/
    const T& getTop() const {
        if (head == nullptr) {      // if the list is empty, throw an exception
            throw runtime_error("List is Empty");
        }
        return head->data;
    }

    /** Operator << : Print the Nodes of the linked list **/
    friend ostream& operator<<(ostream& os,const LinkedList<T>& list) {
        Node<T>* curr = list.head;      // pointer to Node (start at head)
        while (curr != nullptr) {
            curr->data.printDetails();
            curr = curr->Next;
        }
        return os;
    }

    /** Default Destructor **/
    ~LinkedList() {
        while(head != nullptr) {
            deleteNode();
        }
    };
};
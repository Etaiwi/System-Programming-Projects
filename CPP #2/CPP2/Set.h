// Assignment C++: 2

#pragma once

#ifndef __SET_H
#define __SET_H
#include "ostream"
using namespace std;
#define defaultMaxSize 1000
#define initialSize 0
#endif //__SET_H

/**
    Set Class will maintain a Set and all the functionality given:
    the Set will hold an array of elements and will be able to print them and use operators as requested
**/

class Set {
private:
    int maxSize;        // Max Size for the array of the Set
    int currentSize;        // current number of items in the array of the Set
    int *arr;       // pointer to the dynamically allocated memory of the array of the Set
public:
    Set();      // initialize an array with default size maxSize = 1000
    explicit Set(int maxSize);      // initialize array with given size maxSize
    Set(const Set& other);      // Copy Constructor
    int getCurrentSize() const;     // return current Size of the array
    void updatemaxSize();       // check if there is a need to increase the array max size and if there is, do it by doubling it
    bool check_if_unique(int elem) const;       // check if a new element is already in the array of the object
    Set& operator=(const Set& other);        // assignment operator
    void operator+=(int elem);      // addition assignment operator
    Set operator+(const Set& other) const;       // addition operator between Sets
    Set operator+(int elem) const;        // addition operator in the form of Set + elem
    friend Set operator+(int elem, const Set& set);     // addition operator in the form of elem + Set
    bool operator>(const Set& other) const;     // check if size is bigger operator
    int operator[](int n) const;        // [] operator return arr[i] of the Set
    friend ostream& operator<<(ostream& os, const Set& set);        // print operator prints to the screen the Set's array
    ~Set();     // Destructor deletes the dynamic memory that array holds
};
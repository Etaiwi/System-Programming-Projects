// Assignment C++: 2


#include "Set.h"

/** initialize an array with default size maxSize = 1000 **/
Set::Set():maxSize(defaultMaxSize), currentSize(initialSize), arr(new int[maxSize]) {}

/** initialize array with given size maxSize **/
Set::Set(int maxSize):maxSize(maxSize),currentSize(initialSize), arr(new int[maxSize]) {}

/** Copy Constructor, create a new Set with same values and a new allocated memory for the array **/
Set::Set(const Set& other) {
    maxSize = other.maxSize;
    currentSize = other.currentSize;
    arr = new int[maxSize];     // allocate new memory for the array
    for (int i = 0; i < currentSize; i++) arr[i] = other[i];        // deep copy the values to the new array
}

/** return current Size of the array **/
int Set::getCurrentSize() const {
    return currentSize;
}

/** check if there is a need to increase the array max size and if there is, do it by doubling it **/
void Set::updatemaxSize() {
    if (currentSize == maxSize) {       // if the currentSize is at the maximum
        maxSize *= 2;       // update maxSize to double the size
        int *newArr = new int[maxSize];     // initialize a new array double the original maxSize
        for (int i = 0; i < maxSize / 2; i++) newArr[i] = arr[i];       // copying to the new array the elements of the object
        delete[] arr;       // deleting the old array
        arr = newArr;       // appoint the new array to the object
    }
}

/** check if a new element is already in the array of the object **/
bool Set::check_if_unique (const int elem) const {
    for (int i = 0; i < currentSize; i++) {     // run on all elements in the array
        if (arr[i] == elem) return false;       // check if there is even 1 element in the array that is the same as elem
    }
    return true;        // we get here only if the new element is unique to the Set's array
}

/** = operator: check for self-assignment, if not, will make a deep assignment using other **/
Set& Set::operator=(const Set& other) {
    if (this == &other) return *this;       // check for self-assignment
    else {      // not a self-assignment
        delete[] arr;       // delete allocated array
        maxSize = other.maxSize;      // update maxSize to other maxSize
        currentSize = other.currentSize;      // update currentSize to other currentSize
        arr = new int[maxSize];       // allocate new memory to array based on maxSize of other
        for (int i = 0; i < maxSize; i++) arr[i] = other[i];        // allocate values of the array of other to given object
        return *this;
    }
}

/** += operator: add a new element to a Set's array if its not already inside and update sizes accordingly **/
void Set::operator+=(const int elem) {
    if (!check_if_unique(elem)) return;       // new element already exists in the array
    else {      // new element is unique to the Set's array
        updatemaxSize();     // check and update if needed the size of the array
        arr[currentSize] = elem;        // appoint the new element to the end of the array
        currentSize += 1;       // increase the current size of the array by 1
    }
}

/** + operator with given Set: return a new Set that include elem if its not already inside the given Set,  Set activates the operator **/
Set Set::operator+(int elem) const {
    Set temp = *this;     // Copy Constructor temp = set
    for (int i = 0; i < currentSize; i++) temp += arr[i];      // add the array of the given Set to the temp Set
    temp += elem;       // add the new element to temp Set
    return temp;        // return by value the temp set
}

/** + operator with given Set: return a new Set that include elem if its not already inside the given Set,  int activates the operator **/
Set operator+(int elem, const Set& set) {        // addition operator for a new element
    Set temp = set;     // Copy Constructor temp = set
    for (int i = 0; i < set.getCurrentSize(); i++) temp += set[i];      // add the array of the given Set to the temp Set
    temp += elem;       // add the new element to temp Set
    return temp;        // return by value the temp set
}

/** + operator with given Set: return a new Set that is the unity of the 2 Sets **/
Set Set::operator+(const Set& other) const {
    Set temp = *this;       // Copy Constructor temp = this Set
    for (int i = 0; i < other.currentSize; i++) temp += other[i];       // uniquely add all elements from other Set to temp
    return temp;        // return by value temp Set
}

/** > operator: return true if activating object has more members in its array than other Set, false otherwise **/
bool Set::operator>(const Set& other) const {
    if(currentSize > other.currentSize) return true;
    else return false;
}

/** [] operator: return the Set's array in the n spot arr[i] **/
int Set::operator[](const int n) const {
    return arr[n];
}

/** << operator: print to the screen the Set's array with given format, allow chaining **/
ostream& operator<<(ostream& os, const Set& set) {       // print operator prints to the screen the Set's array
    os << "{";
    int i;
    for (i = 0; i < set.getCurrentSize() - 1; i++)
        os << set[i] << ", ";      // while there is more than 1 element in the array, print accordingly
    os << set[i];     // print last element in the array
    os << "}";
    return os;
}

/** Destructor deletes the dynamic memory that array holds **/
Set::~Set() {
    delete[](arr);      // delete the dynamically allocated array
}


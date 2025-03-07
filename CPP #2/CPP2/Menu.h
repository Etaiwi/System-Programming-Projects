// Assignment C++: 2


#pragma once

#include "Set.h"
#include "myQueue.h"
#include <iostream>
using namespace std;

/**
    Menu Class create an infinite loop that will get input from the user and do will continue until
    user decide to end the program
**/

class Menu {
public:
    Menu();                  // default Constructor
    void mainMenu();         // call main Menu
    void setMenu();          // call Set Menu
    void queueMenu();        // call Queue Menu
    ~Menu();                 // default Destructor
};
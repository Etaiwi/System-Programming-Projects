/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/
#pragma once

#include "VendingMachine.h"
#include "Stack.h"
#include <iostream>
using namespace std;

/**
    Menu Class initiate an infinite loop that responsible to run the code
    through it we can access the Shop and Stack and close the program
**/

class Menu {
private:
    void ShopMenu();    // running Shop Menu
    void StackMenu();   // running Stack Menu
public:
    Menu();             // default Constructor
    void mainMenu();    // running Main Menu
    ~Menu();            // default Destructor
};
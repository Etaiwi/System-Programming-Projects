/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/
#pragma once

#include "DispenserType.h"
#include "CashRegister.h"
#include <iostream>
using namespace std;

/**
    VendingMachine Class is the interface between the user and the selling machine.
    through it we make transactions and give basic necessary info to the user.
**/

class VendingMachine {
private:
    DispenserType waterDis;             // water
    DispenserType colaDis;              // cola
    DispenserType grapeDis;             // grape
    CashRegister counter;               // cash register
public:
    VendingMachine();                   // vending machine constructor - initiate juice dispensers and cash register with initial values
    void sellProduct(char c);           // initiate a selling of 1 product given by char c
    int getNoOfItems(char c) const;     // print the amount of stock remaining for given product given by char c
    ~VendingMachine();                  // default Destructor
};
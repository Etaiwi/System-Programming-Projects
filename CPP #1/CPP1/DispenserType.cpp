/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/

#include "DispenserType.h"

DispenserType::DispenserType(int numberOfItems, int cost) : numberOfItems(numberOfItems), cost(cost) {}     // Stock amount to numberOfItems and cost amount to cost field

int DispenserType::getNoOfItems() const {   // return the numberOfItems of given Dispenser
    return numberOfItems;
}

int DispenserType::getCost() const {    // return the cost of given Dispenser
    return cost;
}

void DispenserType::makeSale() {    // initiate a sell of given Dispenser
    numberOfItems -= 1;
}

DispenserType::~DispenserType() = default;

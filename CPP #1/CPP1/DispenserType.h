/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/
#pragma once

/**
    DispenserType class is responsible for the specific juice.
    This class track the amount of stock in a given juice and include the cost of it.
    Using this class we can print out the cost and update the stock.
**/

class DispenserType {
private:
    int numberOfItems;      // amount of stock left
    int cost;               // the cost of this specific juice
public:
    DispenserType(int numberOfItems, int cost); // create Dispenser with given Stock and Cost
    int getNoOfItems() const;                   // return the numberOfItems of given Dispenser
    int getCost() const;                        // return the cost of given Dispenser
    void makeSale();                            // initiate a sell of given Dispenser
    ~DispenserType();                           // default Destructor
};
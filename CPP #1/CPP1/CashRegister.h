/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/
#pragma once

/**
    CashRegister class is responsible for the cash.
    It has the cash that the register holds currently, have a method to return that amount
    and can update the cash amount with a given integer.
**/

class CashRegister {
private:
    int cashOnHands;                    // current balance
public:
    CashRegister();                     // default Constructor with 0 cash on hands
    explicit CashRegister(int x);       // Constructor that initiate with x amount to cash on hands
    int getCurrentBalance() const;      // return the current cash on hands
    void acceptAmount(int added_money); // add given money to cash on hands.
    ~CashRegister();                    // default Destructor
};

// we can see that we can use only one CashRegister(int x = 0) but given the requirements we make 2 functions
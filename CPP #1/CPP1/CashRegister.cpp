/* Assignment C++: 1
   Author: Etai Wigman, ID: 315875385
   Author: Natan Davidov, ID: 211685300
*/

#include "CashRegister.h"

CashRegister::CashRegister(): cashOnHands(0){}         // default Constructor with 0 cash on hands
CashRegister::CashRegister(int x): cashOnHands(x){}    // Constructor that initiates with x amount to cash on hands

int CashRegister::getCurrentBalance() const {           // return the current cash on hands
    return cashOnHands;
}

void CashRegister::acceptAmount(int added_money) {      // add given money to cash on hands.
    cashOnHands += added_money;
}

CashRegister::~CashRegister() = default;                // default Destructor

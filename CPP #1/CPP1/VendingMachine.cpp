// Assignment C++: 1


#include "VendingMachine.h"

VendingMachine::VendingMachine() :
    waterDis(10, 5),    // initiate water Dispenser with 10 items that each cost 5
    colaDis(5, 7),      // initiate cola Dispenser with 5 items that each cost 7
    grapeDis(4, 6),     // initiate grape Dispenser with 4 items that each cost 6
    counter(0) {}                     // initiate the Cash Register with initial value 0

int VendingMachine::getNoOfItems(char c) const{  // print the given juice stock according to given char
    if (c == 'w') return waterDis.getNoOfItems();
    else if (c == 'c') return colaDis.getNoOfItems();
    else if (c == 'g') return grapeDis.getNoOfItems();
    exit(1);
}

void VendingMachine::sellProduct(char c) {  // initiate selling of given juice by given char c
    DispenserType *juice;       // pointer to the chosen DispenserType
    if (c == 'w') juice = &waterDis; // given juice is water
    else if (c == 'c') juice = &colaDis;  // given juice is cola
    else if (c == 'g') juice = &grapeDis; // given juice is grape
    else exit(1);       // a bug has occurred

    if (juice->getNoOfItems() == 0) {   // if given juice is out of stock
        cout << endl << "*********************************" << endl << endl << endl;
        cout << "**Sorry, this item is sold out.**" << endl << endl << endl;
        cout << "*********************************" << endl << endl;
    }
    else {  // given juice stock is not empty
        int payment, paid = 0;      // payment for user given money; paid is for the second chance to pay up
        cout << "Please deposit " << juice->getCost() << " NIS" << endl; // print the price of the given juice
        cin >> payment;
        paid += payment;
        if (paid < juice->getCost()) {  // not enough paid on the first go
            cout << "Please deposit another " << juice->getCost()-paid << " NIS" << endl;
            cin >> payment;
            paid += payment;
        }
        if (paid < juice->getCost()) {  // not enough paid on the second go
            cout << "The amount is not enough. Collect what you deposited." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
        }
        else {  // user paid enough
            cout << "Collect your item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
            juice->makeSale();      // decrease stock by 1 for given juice
            this->counter.acceptAmount(paid);   // update cash on hands
        }
    }
}

VendingMachine::~VendingMachine() = default;    // default Destructor

// Assignment C++: 1


#include "Menu.h"

Menu::Menu() = default;    // default Constructor

void Menu::mainMenu() {     // Main Menu loop
    int main_num;
    do {
        cout << "(1) Beverage Machine" << endl;
        cout << "(2) Integer Stack" << endl;
        cout << "(3) Exit" << endl;
        cin >> main_num;
        if (main_num == 1) this->ShopMenu();    // if user choose 1, go to shop menu
        else if (main_num == 2) this->StackMenu();      // if user choose 2, go to stack menu
        else if (main_num == 3) cout << "Goodbye!" << endl;     // if user choose 3, exit program
        else cout << "Invalid selection." << endl;      // user selected invalid selection
    } while (main_num != 3);        // until user want to exit program
}

void Menu::ShopMenu() { // Shop Menu loop
    int shop_num;
    VendingMachine M;
    //DispenserType water(10, 5); // create DispenserType water with 10 items that each cost 5 NIS
    //DispenserType cola(5, 7);   // create DispenserType water with 5 items that each cost 7 NIS
    //DispenserType grape(4, 6);  // create DispenserType water with 4 items that each cost 6 NIS
    do {
        cout << "*** Beverage Machine ***" << endl << endl;
        cout << "Inventory details:" << endl;
        cout << "Water:       " << M.getNoOfItems('w') << endl;
        cout << "Cola:        " << M.getNoOfItems('c') << endl;
        cout << "Grape juice: " << M.getNoOfItems('g') << endl << endl;
        cout << "To select an item, enter" << endl;
        cout << "1 For Water" << endl;
        cout << "2 For Cola" << endl;
        cout << "3 For Grape juice" << endl;
        cout << "4 To exit" << endl;
        cin >> shop_num;
        if (shop_num == 1) M.sellProduct('w');      // sell water
        else if (shop_num == 2) M.sellProduct('c');     // sell cola
        else if (shop_num == 3) M.sellProduct('g');     // sell grape juice
        else if (shop_num == 4) cout << "Thank you!" << endl;       // finished shopping for juice
        else cout << "Invalid selection." << endl;      // invalid selection
    } while (shop_num != 4);
}

void Menu::StackMenu() {    // Stack Menu loop
    int stack_num;
    int new_element;
    Stack S;
    do {
        cout << "*** Manage your integer stack ***" << endl;
        cout << "1 Push new element" << endl;
        cout << "2 Pop element" << endl;
        cout << "3 Show the first element" << endl;
        cout << "4 Check if empty" << endl;
        cout << "5 to exit" << endl;
        cin >> stack_num;
        if (stack_num == 1) {       // insert new element to the Stack
            cout << "Please insert the new element:";
            cin >> new_element;
            S.push(new_element);
        }
        else if (stack_num == 2) {      // pop an element from Stack if not empty
            S.isEmpty() ? cout << "Stack empty" << endl : cout << "Removing " << S.pop() << endl;
        }
        else if (stack_num == 3) cout << "The first element is: " << S.peek() << endl;      // peek to the element on top
        else if (stack_num == 4) {      // check if Stack is empty
            S.isEmpty() ? cout << "The stack is empty" << endl : cout << "The stack is not empty" << endl;
        }
        else if (stack_num == 5) cout << "Thank you!" << endl;      // finished with Stack
        else cout << "Invalid selection." << endl;      // invalid selection
    } while (stack_num != 5);
}

Menu::~Menu() = default;    // default Destructor
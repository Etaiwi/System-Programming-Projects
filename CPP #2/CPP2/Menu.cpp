// Assignment C++: 2


#include "Menu.h"

Menu::Menu() = default;     // empty Constructor

/** Main Menu loop **/
void Menu::mainMenu() {
    int main_num;
    do {
        cout << "(1) Set Menu" << endl;
        cout << "(2) Integer Queue Menu" << endl;
        cout << "(3) Exit" << endl;
        cin >> main_num;
        if (main_num == 1) setMenu();       // if user chooses 1, go to the Set Menu
        else if (main_num == 2) queueMenu();        // if user chooses 2, go to the Stack Menu
        else if (main_num == 3) cout << "Goodbye!" << endl;     // if user choose 3, exit program
        else cout << "Invalid selection." << endl;      // user selected invalid selection
    } while (main_num != 3);        // until user want to exit program
}

/** Set Menu loop **/
void Menu::setMenu() {
    int set_num, elem;
    Set Set_1, Set_2;        // initialize 3 empty sets
    do {
        cout << "*** Welcome to Set Menu ***\n"
                "To select an item, enter\n"
                "1 Show set 1\n"
                "2 Show set 2\n"
                "3 add element to set 1\n"
                "4 add element to set 2\n"
                "5 Show set1 U set 2 (union)\n"
                "6 to exit" << endl;
        cin >> set_num;     // user input
        if (set_num == 1) {     // print Set 1
            if (Set_1.getCurrentSize() == 0) cout << "Set 1 is empty" << endl;
            else cout << Set_1 << endl;
        }
        else if (set_num == 2) {        // print Set 2
            if (Set_2.getCurrentSize() == 0) cout << "Set 2 is empty" << endl;
            else cout << Set_2 << endl;
        }
        else if (set_num == 3) {        // add an element to Set 1
            cout << "Give a number: ";
            //Set_1 += cin >> elem;
            cin >> elem;
            Set_1 += elem;      // add elem to Set_1
        }
        else if (set_num == 4) {        // add an element to Set 2
            cout << "Give a number: ";
            //Set_2 += cin >> elem;
            cin >> elem;
            Set_2 += elem;
        }
        else if (set_num == 5) {        // print Set_1 U Set_2
            if ((Set_1.getCurrentSize() == 0) && (Set_2.getCurrentSize() == 0)) cout << "The union is empty" << endl;
            else cout << Set_1 + Set_2 << endl;
        }
        else if (set_num == 6) {}
        else cout << "Invalid selection." << endl;
    } while (set_num != 6);
}

/** Queue Menu loop **/
void Menu::queueMenu() {
    int queue_num, queue_size, elem;
    cout << "Enter the size of the queue: ";
    cin >> queue_size;
    myQueue Q(queue_size);      // create Queue Q with user's given queue size
    do {
        cout << endl;
        cout << "*** Welcome to Queue Menu ***\n"
                "To select an item, enter\n"
                "1 Show Queue\n"
                "2 Insert new element\n"
                "3 Remove element\n"
                "4 Check the first element\n"
                "5 to exit" << endl;
        cin >> queue_num;
        if (queue_num == 1) {       // print Queue Q
            if (Q.isEmpty()) cout << "The queue is empty" << endl;
            else cout << Q << endl;
        }
        else if (queue_num == 2) {      // enqueue element to Q if possible and print whats needed
            cout << "insert new element: ";
            cin >> elem;        // new element to insert
            if (Q.enQueue(elem)) cout << "The new queue:" << endl << Q << endl;     // enqueue and print Q if the enqueue succeeded
            else cout << "Queue is full" << endl;       // if Q is full print that its full
        }
        else if (queue_num == 3) {      // remove an element from the queue Q
            Q.deQueue();
            if (Q.getSize() == 0) cout << "Queue is empty" << endl;      // if Q is already empty or had 1 element, print that its empty
            else cout << "The new queue:" << endl << Q << endl;      // Q is not empty after dequeue

        }
        else if (queue_num == 4) {      // print the first element if queue is not empty, and if it is empty, print it
            if(Q.isEmpty()) cout << "Queue is empty" << endl;      // if Q is empty, print it
            else cout << *Q.peek() << endl;      // if Q is not empty, print the first element
        }
        else if (queue_num == 5) {}
        else cout << "Invalid selection." << endl;
    } while (queue_num != 5);
}

/** default Destructor **/
Menu::~Menu() = default;
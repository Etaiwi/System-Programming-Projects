// Assignment C++: 3


#include "Menu.h"

/** Menu Default Constructor **/
Menu::Menu() = default;

/** Main Menu loop **/
void Menu::mainMenu() {
    LinkedList<Shape*> shape_list;
    LinkedList<Shape*>* p_shape_list = &shape_list;
    int main_num;
    int shape_num;
    do {
        cout << "=======================================" << endl;
        cout << "<1> Add element to the list" << endl;
        cout << "<2> Remove the last shape from list" << endl;
        cout << "<3> Print the last shape" << endl;
        cout << "<4> Exit" << endl;
        cout <<"=======================================" << endl;
        cin >> main_num;

        if (main_num == 1) {       // add an element to the list
            cout << endl;
            cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle: ";
            cin >> shape_num;
            if (shape_num == 1) SquareMenu(p_shape_list);
            else if (shape_num == 2) CircleMenu(p_shape_list);
            else if (shape_num == 3) OrthogonalTriangleMenu(p_shape_list);
            else cout << "Invalid choice" << endl;
        }

        else if (main_num == 2) {       // remove the last shape from the shape list
            try {
                Shape* shape = shape_list.deleteNode();        // delete the first shape in the shape list
                delete shape;
            }
            catch(...) {        // we get here if the shape list is empty and an exception was thrown
                cout << "Exception: The List is empty!" << endl;
                cout << "please try again" << endl;
            }
        }

        else if (main_num == 3) {       // print the last shape
            try {
                const Shape* shape = shape_list.getTop();
                shape->printDetails();
            }
            catch(...) {
                cout << "Exception: List is empty!" << endl << endl;        // we get here if the shape list is empty and an exception was thrown
            }
        }

        else if (main_num == 4) {       // finish the program and delete all allocated memory
            try {
                while((p_shape_list->deleteNode()) != nullptr);
            }
            catch(...) {}
        }
        else cout << "Invalid selection." << endl;      // invalid selection
    } while(main_num != 4);     // get out of the program
}

/** Square Creation Menu **/
void Menu::SquareMenu(LinkedList<Shape*>* p_shape_list) {
    string color;
    double side_length;
    bool flag = true;
    while(flag) {       // in while loop until we get a valid input
        flag = false;
        cout << "Enter square's color: ";
        cin >> color;
        cout << "Enter square's side length: ";
        cin >> side_length;
        try {
            if (!(color == "red" || color == "blue" || color == "green")) {     // valid color
                cout << "Exception: color must be red green or blue" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Wrong Color chosen");
            }
            else if(side_length <= 0) {     // valid side length
                cout << "Exception: The side must be positive" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Side Length must be positive");
            }
        }
        catch (...) {
            flag = true;
        }
    }
    p_shape_list->insert(new Square(color, side_length));       // insert new Square to the List
}

/** Circle Creation Menu **/
void Menu::CircleMenu(LinkedList<Shape*>* p_shape_list) {
    string color;
    double radius;
    bool flag = true;
    while(flag) {       // in while loop until we get a valid input
        flag = false;
        cout << "Enter circle's color: ";
        cin >> color;
        cout << "Enter circle's radius: ";
        cin >> radius;
        try {
            if (!(color == "red" || color == "blue" || color == "green")) {     // valid color
                cout << "Exception: color must be red green or blue" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Wrong Color chosen");
            }
            else if(radius <= 0) {     // valid radius
                cout << "Exception: The radius must be positive!" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Radius must be positive");
            }
        }
        catch (...) {
            flag = true;
        }
    }
    p_shape_list->insert(new Circle(color, radius));       // insert new Circle to the List
}

/** OrthogonalTriangle Creation Menu **/
void Menu::OrthogonalTriangleMenu(LinkedList<Shape*>* p_shape_list) {
    string color;
    double side;
    bool flag = true;
    while(flag) {       // in while loop until we get a valid input
        flag = false;
        cout << "Enter Triangle's color: ";
        cin >> color;
        cout << "Enter Triangle's side: ";
        cin >> side;
        try {
            if (!(color == "red" || color == "blue" || color == "green")) {     // valid color
                cout << "Exception: color must be red green or blue" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Wrong Color chosen");
            }
            else if(side <= 0) {     // valid side
                cout << "Exception: The sides must be greater then zero" << endl;
                cout << "please try again" << endl;
                throw runtime_error("Side must be positive");
            }
        }
        catch (...) {
            flag = true;
        }
    }
    p_shape_list->insert(new OrthogonalTriangle(color, side));       // insert new Triangle to the List
}

/** Menu Default Destructor **/
Menu::~Menu() = default;
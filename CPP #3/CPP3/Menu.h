// Assignment C++: 3


#pragma once
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"
#include "string"
#include "LinkedList.h"
#include "Node.h"
#include "iostream"
using namespace std;

/**
    Menu Class create an infinite loop that will get input from the user and do will continue until
    user decide to end the program
**/

class Menu {
public:
    Menu();     // Default Constructor
    void mainMenu();        // Main Menu Loop
    void SquareMenu(LinkedList<Shape*>*);      // Square creation menu
    void CircleMenu(LinkedList<Shape*>*);      // Circle creation menu
    void OrthogonalTriangleMenu(LinkedList<Shape*>*);      // OrthogonalTriangle creation menu
    ~Menu();        // Default Destructor
};
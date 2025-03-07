// Assignment C++: 3


#pragma once
#include "Shape.h"
#include "cmath"
#include "iostream"
using namespace std;
#define default_side_length 1

/** Class Square : inherit from Shape as its base, add a field for side length and allow the user to draw, get the area and get the perimeter of the Square **/
class Square : public Shape {
private:
    double sidelength;
public:
    Square();       // Default Constructor
    Square(const string&, double);     // Constructor
    double getPerimeter() const override;     // Override getPerimeter
    double getArea() const override;      // Override getArea
    void draw() const;        // Draw Method
    void printDetails() const override;     // Print Square Details
    ~Square() override;      // Default Destructor
};

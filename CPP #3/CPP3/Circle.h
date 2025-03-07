// Assignment C++: 3


#pragma once
#include "Shape.h"
#include <cmath>
#include "iostream"
using namespace std;
#define default_radius 1

class Circle : public Shape {
private:
    double radius;
public:
    Circle();       // Default Constructor
    Circle(const string&, double);     // Constructor
    double getPerimeter() const override;     // Override getPerimeter
    double getArea() const override;      // Override getArea
    void printDetails() const override;     // Print Circle Details
    ~Circle() override;      // Default Destructor
};

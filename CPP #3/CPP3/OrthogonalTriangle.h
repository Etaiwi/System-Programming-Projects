// Assignment C++: 3


#pragma once
#include "Shape.h"
#include "cmath"
#include "iostream"
using namespace std;
#define default_side 1

class OrthogonalTriangle : public Shape {
private:
    double side;
public:
    OrthogonalTriangle();       // Default Constructor
    OrthogonalTriangle(const string&, double);     // Constructor
    double getPerimeter() const override;     // Override getPerimeter
    double getArea() const override;      // Override getArea
    void draw() const;        // Draw Method
    void printDetails() const override;
    ~OrthogonalTriangle() override;      // Default Destructor
};

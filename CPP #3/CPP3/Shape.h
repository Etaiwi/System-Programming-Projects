// Assignment C++: 3


#pragma once
#include "string"
using namespace std;

/** Class Shape : this class hold the color of the shape and demand the derived classes to build the given pure virtual methods **/
class Shape {
protected:
    string color;       // Shape's Color
public:
    Shape();        // Default Constructor
    explicit Shape(const string&);     // Constructor
    virtual double getPerimeter() const = 0;      // Pure Virtual Method
    virtual double getArea() const = 0;       // Pure Virtual Method
    virtual void printDetails() const = 0;      // Pure Virtual Method
    virtual ~Shape();       // Default Destructor
};
// Assignment C++: 3


#include "OrthogonalTriangle.h"

/** OrthogonalTriangle Default Constructor **/
OrthogonalTriangle::OrthogonalTriangle() : side(default_side) {}

/** OrthogonalTriangle Constructor : Initiate Triangle with given color and given side length **/
OrthogonalTriangle::OrthogonalTriangle(const string& color, double side) : Shape(color), side(side) {}

/** OrthogonalTriangle getPerimeter : Return the perimeter of the Triangle **/
double OrthogonalTriangle::getPerimeter() const {
    return side + side + sqrt(2)*side;
}

/** Triangle getArea : Return the Area of the Triangle **/
double OrthogonalTriangle::getArea() const {
    return side * side / 2;
}

/** Triangle draw : Draw the Triangle **/
void OrthogonalTriangle::draw() const {
    for (int n = 0; n < floor(side); n++) {
        for (int m = 0; m <= n; m++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

/** Print Triangle Details **/
void OrthogonalTriangle::printDetails() const {
    cout << endl;
    cout << "OrthogonalTriangle details: color=" << color << ", side=" << side << endl;
    cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
    draw();
}

/** OrthogonalTriangle Default Destructor **/
OrthogonalTriangle::~OrthogonalTriangle() = default;
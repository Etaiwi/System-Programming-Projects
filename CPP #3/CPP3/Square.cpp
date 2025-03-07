// Assignment C++: 3


#include "Square.h"

/** Square Default Constructor **/
Square::Square() : sidelength(default_side_length) {}     // default Square is a point

/** Square Constructor : Initiate Square with given color and given side length **/
Square::Square(const string& color, double sidelength) : Shape(color), sidelength(sidelength) {}

/** Square getPerimeter : Return the perimeter of the Square **/
double Square::getPerimeter() const  {
    return 4 * sidelength;
}

/** Square getArea : Return the Area of the Square **/
double Square::getArea() const {
    return sidelength * sidelength;
}

/** Square draw : Draw the Square **/
void Square::draw() const {
    for (int n = 0; n < floor(sidelength); n++) {
        for (int m = 0; m < floor(sidelength); m++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

/** Print Square Details **/
void Square::printDetails() const {
    cout << endl;
    cout << "Square details: color=" << color << ", side length=" << sidelength << endl;
    cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
    draw();
}

/** Square Default Destructor **/
Square::~Square() = default;
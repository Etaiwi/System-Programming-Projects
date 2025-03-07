// Assignment C++: 3


#include "Circle.h"

/** Circle Default Constructor **/
Circle::Circle() : radius(default_radius) {}       // default circle is the unit circle

/** Circle Constructor : Initiate Circle with given color and given radius **/
Circle::Circle(const string& color, double radius) : Shape(color), radius(radius) {}

/** Circle getPerimeter : Return the perimeter of the Circle **/
double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

/** Circle getArea : Return the Area of the Circle **/
double Circle::getArea() const {
    return M_PI * radius * radius;
}

/** Print Circle Details **/
void Circle::printDetails() const {
    cout << endl;
    cout << "Circle details: color=" << color << ", radius=" << radius << endl;
    cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;
    cout << endl;
}

/** Circle Default Destructor **/
Circle::~Circle() = default;
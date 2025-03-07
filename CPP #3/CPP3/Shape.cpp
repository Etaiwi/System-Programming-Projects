// Assignment C++: 3


#include "Shape.h"

/** Shape Default Constructor **/
Shape::Shape() = default;

/** Shape Constructor : Initialize given color to the Shape's color **/
Shape::Shape(const string& color) : color(color) {};

/** Shape Default Destructor **/
Shape::~Shape() = default;
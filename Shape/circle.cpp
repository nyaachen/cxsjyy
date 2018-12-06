#include "circle.h"
#include <cmath>
#define PAI asin(1)

shape::Circle::Circle() : radious(0) {}

shape::Circle::Circle(double r) : radious(r) {}

double shape::Circle::calculate_perimeter() const {
    return 2*PAI*radious;
}

double shape::Circle::calculate_area() const {
    return PAI*radious*radious;
}

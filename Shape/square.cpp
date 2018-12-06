#include "square.h"

shape::Square::Square() : base(0), height(0) {}

shape::Square::Square(double b, double h) : base(b), height(h) {}

double shape::Square::calculate_perimeter() const {
    return 2*(base+height);
}

double shape::Square::calculate_area() const {
    return base*height;
}

#ifndef SQUARE_H
#define SQUARE_H

#include "shape2d.h"

namespace shape {
    class Square : public Shape2D {
    private:
        double base;
        double height;
    public:
        Square();
        Square(double b, double h);
        ~Square() = default;

        double calculate_perimeter() const override;
        double calculate_area() const override;
    };
}

#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape2d.h"

namespace shape {
    class Rectangle : public Shape2D {
    private:
        double base;
        double height;
        double sita; // 底边上的任意一个内角
    public:
        Rectangle();
        Rectangle(double b, double h, double s);
        ~Rectangle() = default;

        double calculate_perimeter() const override;
        double calculate_area() const override;
    };
}

#endif

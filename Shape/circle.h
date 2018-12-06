#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape2d.h"

namespace shape {
    class Circle : public Shape2D {
    private:
        double radious;
    public:
        Circle();
        Circle(double r);
        ~Circle() = default;

        double calculate_perimeter() const override;
        double calculate_area() const override;
    };
}

#endif

#ifndef SHAPE2D_H
#define SHAPE2D_H

namespace shape {
    class Shape2D {
    public:
        Shape2D() = default;
        virtual ~Shape2D() = default;
        virtual double calculate_perimeter() const = 0;
        virtual double calculate_area() const = 0;
    };
};

#endif

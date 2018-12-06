#include "rectangle.h"
#include <cmath>

shape::Rectangle::Rectangle() : base(0), height(0), sita(0) {}

shape::Rectangle::Rectangle(double b, double h, double s) : base(b), height(h), sita(s) {}

double shape::Rectangle::calculate_perimeter() const {
    double t1 = sin(sita);
    if(t1 == 0) {return 0;} // 不是一个三角形，或者是默认参数
    else {
        double l1 = height / t1; // 底角对应的斜边的长度
        double b1 = height * cos(sita); // 对应的斜边在底边上的投影长度
        double b2 = base - b1; // 另一条斜边在底边的投影长度
        double l2 = sqrt(b2*b2+height*height); // 另一条斜边的长度
        return base + l1 + l2;
    }
}

double shape::Rectangle::calculate_area() const {
    return base*height/2;
}

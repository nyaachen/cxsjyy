#include "shape2d.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

#include <iostream>
using namespace shape;
using namespace std;

int main() {
    Shape2D *p;

    p = new Circle(2);
    cout << "圆\n周长：" << p->calculate_perimeter() << "\n面积：" << p->calculate_area() << endl;
    delete p;

    p = new Rectangle(6,10, 1);
    cout << "三角形\n周长：" << p->calculate_perimeter() << "\n面积：" << p->calculate_area() << endl;
    delete p;

    p = new Square(6, 10);
    cout << "正方形\n周长：" << p->calculate_perimeter() << "\n面积：" << p->calculate_area() << endl;
    delete p;

    return 0;
}

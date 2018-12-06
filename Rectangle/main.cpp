#include <iostream>

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;
    virtual void Area() = 0;
};

class Rectangle : public Shape{
protected:
    double base;
    double height;
public:
    Rectangle() : Shape(), base(0), height(0) {}
    Rectangle(double b, double h) : Shape(), base(b), height(h) {}
    virtual ~Rectangle() = default;
    void Area() override {
        std::cout << "Area of Rectangle = " << base*height/2 << std::endl;
    }
};

class Circle : public Shape {
    static constexpr double PAI = 3.14159265358;
private:
    double radious;
public:
    Circle() : Shape(), radious(0) {}
    Circle(double r) : Shape(), radious(r) {}
    virtual ~Circle() = default;
    void Area() override {
        std::cout << "Area of Circle = " << PAI*radious*radious << std::endl;
    }
};

class Square : public Rectangle {
public:
    Square() : Rectangle() {}
    Square(double a, double b) : Rectangle(a, b) {}
    virtual ~Square() = default;
    void Area() override {
        std::cout << "Area of Square = " << base*height << std::endl;
    }
};

int main() {
    Square a(10,3);
    a.Area();
    return 0;
}

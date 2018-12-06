#include <iostream>
#include <cstring>
#define PAI 3.14159265358

class Circle {
private:
    double radious;
public:
    Circle() : radious(0) {}
    Circle(double r) : radious(r) {}
    ~Circle() = default;
    double area() {
        return PAI*radious*radious;
    }
};

class Table {
protected:
    char *shape;
    double height;
    char *color;
public:
    Table(const char *shape_, double height_, const char *color_) : shape(nullptr), height(height_), color(nullptr) {
        shape = new char [strlen(shape_)+1];
        strcpy(shape, shape_);
        shape[strlen(shape_)] = '\0';
        color = new char [strlen(color_)+1];
        strcpy(color, color_);
        color[strlen(color_)] = '\0';
    }
    virtual ~Table() {
        delete [] shape;
        delete [] color;
    }
    virtual void print() {
        std::cout << "The shape of table: " << shape << "\nThe height of Table: " << height << "\nThe color of table: " << color << std::endl;
    }
}

class C_Table : public Table, protected Circle {
public:
    C_Table(double height_, double radious_, const char *color_) : table("Circle", height_, color_), Circle(radious_) {}
    void print() override {
        Table::print();
        std::cout << "The area of table: " << area() << std::endl;
    }
}

int main() {
    C_Table t(1.2, 10, "Pink");
    Table &ref = t;
    t.print();
    ref.print();
    return 0;
}

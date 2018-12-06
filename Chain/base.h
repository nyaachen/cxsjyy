#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
    friend std::ostream &operator<<(std::ostream &os, const Base &b);
protected:
    virtual std::ostream &print(std::ostream &os) const = 0;
public:
    Base() = default;
    virtual ~Base() = default;
};

std::ostream &operator<<(std::ostream &os, const Base &b);

#endif

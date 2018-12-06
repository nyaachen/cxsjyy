#include <iostream>

#include "employee.h"

Employee::Employee(const std::string &name, const std::string &pos) : Name(name), position(pos) {}

std::ostream &Employee::print(std::ostream &os) const {
    os << Name << " " << position;
    return os;
}

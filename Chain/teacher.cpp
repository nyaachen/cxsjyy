#include <iostream>

#include "teacher.h"

Teacher::Teacher(const std::string &name, double salary_) : Teacher_Name(name), salary(salary_) {}

std::ostream &Teacher::print(std::ostream &os) const {
    os << Teacher_Name << " " << salary;
    return os;
}

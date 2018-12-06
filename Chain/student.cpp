#include <iostream>

#include "student.h"

Student::Student(const std::string &stu_name, const std::string &stu_id) : Student_Name(stu_name), Student_ID(stu_id) {}

std::ostream &Student::print(std::ostream &os) const {
    os << Student_ID << " " << Student_Name;
    return os;
}

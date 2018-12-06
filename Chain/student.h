#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "base.h"

class Student : public Base {
private:
    std::string Student_Name;
    std::string Student_ID;
protected:
    std::ostream &print(std::ostream &os) const override;
public:
    Student() = default;
    Student(const std::string &stu_name, const std::string &stu_id);
    ~Student() = default;
};

#endif

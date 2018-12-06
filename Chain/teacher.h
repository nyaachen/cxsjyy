#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <iostream>
#include "base.h"

class Teacher : public Base {
private:
    std::string Teacher_Name;
    double salary;
protected:
    std::ostream &print(std::ostream &os) const override;
public:
    Teacher() = default;
    Teacher(const std::string &name, double salary_);
    ~Teacher() = default;
};

#endif

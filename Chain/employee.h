#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include "base.h"

class Employee : public Base {
private:
    std::string Name;
    std::string position;
protected:
    std::ostream &print(std::ostream &os) const override;
public:
    Employee() = default;
    Employee(const std::string &name, const std::string &pos);
    ~Employee() = default;
};

#endif

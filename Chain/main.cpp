#include <iostream>
#include "base.h"
#include "student.h"
#include "teacher.h"
#include "employee.h"
#include "nodep.h"

using namespace std;

int main() {
    Nodep *phead = nullptr, *pend = phead;
    int choice;
    while (true) {
        cout << "请输入要新建的成员类型：1学生2教师3职工\n输入4来结束输入并查看输出" << endl;
        cin >> choice;
        Base *temp = nullptr;
        std::string id, name, position;
        double salary;
        switch(choice) {
        case 1:
            cout << "输入学生的学号和姓名" << endl;
            cin >> id >> name;
            temp = new Student(id, name);
            break;
        case 2:
            cout << "输入教师的姓名和工资" << endl;
            cin >> name >> salary;
            temp = new Teacher(name, salary);
            break;
        case 3:
            cout << "输入职工的姓名和职位" << endl;
            cin >> name >> position;
            temp = new Employee(name, position);
            break;
        case 4:
            break;
        default:
            cout << "你的输入有误，请重试" << endl;
            continue;
        }
        if (choice == 4) break;

        if (phead == nullptr) {
            phead = new Nodep(temp);
            pend = phead;
        }
        else {
            pend->insert(new Nodep(temp));
            pend = pend->next();
        }
    }
    cout << "输出" << endl;
    for (Nodep *iter = phead; iter!=nullptr; iter = iter->next()) {
        cout << **iter << endl;
    }
    cout << "一点点清理工作" << endl;
    while (true) {
        Nodep *temp = phead->remove_after();
        if (temp != nullptr) {
            delete temp->pointer();
            delete temp;
        }
        else {
            delete phead->pointer();
            delete phead;
            break;
        }
    }
    return 0;
}

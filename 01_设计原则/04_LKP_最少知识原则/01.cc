#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 一个对象应该对其他对象有最少的了解。
// 一个类只应该与直接的朋友进行通信
// 直接的朋友: 成员变量、方法的入参，方法的返回值

class CollegeEmployee {
public:
  string id;
};

class CollegeManager {
public:
  auto getCollegeEmployee() {
    vector<CollegeEmployee *> collegeEmployees;
    for (int i = 0; i < 5; i++) {
      collegeEmployees.push_back(
          new CollegeEmployee{"学院员工id: " + to_string(i)});
    }
    return collegeEmployees;
  }

  void printAllEmployee() {
    auto allEmployees = this->getCollegeEmployee();
    for (auto x : allEmployees) {
      cout << x->id << endl;
    }
  }
};

class SchoolEmployee {
public:
  string id;
};

class SchoolManager {
public:
  auto getSchoolEmployee() {
    vector<SchoolEmployee *> schoolEmployees;
    for (int i = 0; i < 5; i++) {
      string id = "总部id: " + to_string(i);
      schoolEmployees.push_back(new SchoolEmployee{id});
    }
    return schoolEmployees;
  }

  void printAllEmployee(CollegeManager *collegeManager) {
    auto schoolEmployees = this->getSchoolEmployee();
    for (auto x : schoolEmployees) {
      cout << x->id << endl;
    }

    collegeManager->printAllEmployee();
  }
};

int main() {
  (new SchoolManager())->printAllEmployee(new CollegeManager());
  return 0;
}

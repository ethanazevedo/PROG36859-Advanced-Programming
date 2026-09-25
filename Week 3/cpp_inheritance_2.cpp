#include <iostream>

using namespace std;

/*
Multi-inheritance

1. multi-level inheritance:
  - a derived class can be the base class of another class
  - inheritance hierarchy
  - constructors: from base to derived
  - destructors: from derived to base

2. multiple inheritance
  - a derived class can inherite from multiple base classes 
  - list all base classes at header
  - call parameterized constructors at initializer list
  - access members of same name, use ClassName::member data/function
*/

//multi-level inheritance demo
class Phone {
protected:
  string model;
public:
  Phone(string m): model(m) { cout << "Creating a Phone...\n"; }
  ~Phone() { cout << "Destroying the Phone...\n"; }
};

class MobilePhone : public Phone {
protected:
  int battery;
public:
  MobilePhone(string m, int b): Phone(m), battery(b) { cout << "Creating a Mobile Phone...\n"; }
  ~MobilePhone() { cout << "Destroying the Mobile Phone...\n"; }
};

class SmartPhone : public MobilePhone {
protected:
  double screen;
public:
  SmartPhone(string m, int b, double s): MobilePhone(m, b), screen(s) {
    cout << "Creating a Smart Phone...\n";
  }
  ~SmartPhone() { cout << "Destroying the Smart Phone...\n"; }
};

//multiple inheritance demo
class Student {
protected:
  string name, school;
public:
  Student(string n, string s): name(n), school(s) {}
  void print() const { cout << "Student: " << name << "@" << school << endl; }
};

class Employee {
protected:
  string name, company;
public:
  Employee(string n, string c): name(n), company(c) {}
  void print() const { cout << "Employee: " << name << "@" << company << endl; }
};

class Intern : public Student, public Employee {
private:
  int months;
public:
  Intern(string sn, string sc, string en, string co, int m): 
      Student(sn, sc), Employee(en, co), months(m) {}
  void printInfo() const {
    cout << "Intern: \n";
    Student::print(); //to call base function, use scope resolution operator ::
    Employee::print();
    cout << "Month: " << months << endl;
  }
};

int main() {
  {
    SmartPhone sp1("NOKIA", 100, 7.2);
  }

  Intern i1("Alex", "Sheridan", "Jack", "OpenAI", 4);
  i1.printInfo();
  i1.Student::print();
  i1.Employee::print();

}

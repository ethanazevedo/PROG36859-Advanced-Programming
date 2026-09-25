/*
1 – Inheritance (Employee System):

Create a base class Employee with members: name and salary. 
Include a member function display() to print basic info.

Create a derived class Manager that inherits from Employee and adds a department member. 
Override display() to include department info.

In main(): Create 2 Employee objects and 2 Manager objects, and call display() on each.
*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;


class Employee{
    protected:
        string name;
        double salary;
    public:
        Employee(string n, double s): name(n), salary(s){};

    virtual void display() const{
        cout << "Hello!" << endl;
    }
};

class Manager : public Employee{
    protected:
        string department;
    public:
        Manager(string n, double s, string d): Employee(n, s), department(d){};

        void display() const override{
            cout << "Hello inc department info!" << endl;
        }

};


int main(){

    Employee e1("Ethan", 2500);
    Employee e2("Joe", 2700);

    e1.display();
    e2.display();

    Manager m1("Amy", 3200, "HR");
    Manager m2("Ashley", 2100, "Econ");

    m1.display();
    m2.display();

    return 0; 
}
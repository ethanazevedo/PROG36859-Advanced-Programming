#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Sorting: re-order data in a contain in ascending or descending order

class Employee {
private:
  int eid;
  string name;
  int age;
  double salary;

public:
  Employee(int i, string n, int a, double s) : eid(i), name(n), age(a), salary(s) {}
  Employee() : Employee(100, "Unknown", 20, 1000.0) {}

  int getEid() const { return eid; }
  string getName() const { return name; }
  int getAge() const { return age; }
  double getSalary() const { return salary; }

  void print() const {
    cout << "Employee: " << eid << ", " << name << ", " << age << ", " << salary << endl;
  }

  bool operator<(const Employee& other) const {
    return eid < other.eid;
  }
};

bool compareNames(const Employee& a, const Employee& b) {
  return a.getName() < b.getName();
}

class AgeComparator {
public:
  bool operator()(const Employee& x, const Employee& y) const {
    return x.getAge() < y.getAge();
  }
};


int main() {
  vector<Employee> employees = {
    Employee(1000, "David", 21, 1122.33),
    Employee(1001, "Alex", 19, 2233.44),
    Employee(999, "Bob", 23, 999.88),
    Employee(1002, "Smith", 25, 4455.66)
  };

  //sort(iterator_begin, iterator_end, [comparator])

  //option 1: no comparator
  //- overload operator < in class
  sort(employees.begin(), employees.end());
  for (const auto& e : employees) e.print();

  //option 2: using a function as comparator
  //- old style
  sort(employees.begin(), employees.end(), compareNames);
  cout << string(40, '-') << endl;
  for (const auto& e : employees) e.print();

  //option 3: functor
  //- like __call__ in Python
  //- overload operator (), then objects are runnable
  sort(employees.begin(), employees.end(), AgeComparator());
  cout << string(40, '-') << endl;
  for (const auto& e : employees) e.print();

  //option 4: lambda (recommended)
  //- what: anonymous function
  //- CPP convert it to functor
  //- syntax: [capture_list](parameters) { body }
  sort(employees.begin(), employees.end(), 
      [](const Employee& a, const Employee& b) { return a.getSalary() < b.getSalary(); }
  );
  cout << string(40, '-') << endl;
  for (const auto& e : employees) e.print();
}



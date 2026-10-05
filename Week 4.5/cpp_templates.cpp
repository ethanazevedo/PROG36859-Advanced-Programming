#include <iostream>
#include <string>

using namespace std;

/*
Templates
- what: generic functions/classes for any data types
- no memory used, compiler generates actual function/class
- for functions, no need to specify type
- for class, must specify type (new C++ CTAD)
*/

class Dog {
private:
  string name;
public:
  Dog(string n = "Unknown Dog") : name(n) {}
  void print() const { cout << "Dog: " << name << endl; }  
};


//function template
template <typename T> //class for old C++ standard
void swapValues(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

//class template
// Family(dad, mom, kids)
const int MAX_KIDS = 10;

template <typename T>
class Family {
private:
  T dad;
  T mom;
  T kids[MAX_KIDS];
  int count;

public: 
  Family(const T& d, const T& m) : dad(d), mom(m), count(0) {}
  T getDad() const { return dad; }
  void setDad(const T& d) { dad = d; }

  T getKid(int pos) const {
    if (pos < 0 || pos >= count) 
      throw out_of_range("Kid index is out of range!");
    return kids[pos];
  }

  bool addKid(const T& k) {
    if (count == MAX_KIDS)
      return false;
    kids[count] = k;
    count++;
    return true;
  }
};


int main() {
  int x = 10, y = 33;
  swapValues(x, y);
  cout << x << ", " << y << endl;

  string s1 = "Spiderman", s2 = "Superman";
  swapValues(s1, s2);
  cout << s1 << ", " << s2 << endl;

  Dog d1("Little Black"), d2("Tiger White");
  swapValues(d1, d2);
  d1.print(); d2.print();


  Family<int> f1(35, 33);
  f1.addKid(10);
  f1.addKid(5);
  cout << f1.getKid(1) << endl;

  Family<string> f2("Alex", "Anna");
  f2.setDad("Bob");
  cout << f2.getDad() << endl;

  Family<Dog> f3(Dog("October"), Dog("Thursday"));
  f3.addKid(Dog("Honey"));
  f3.getKid(0).print();

}



#include <iostream>
#include <string>

using namespace std;

/*
1. Inheritance
  - what: strongest relationship, IS-A
    Student is-a Person, Car is-a Vehicle, Flower is-a Plant, Chair is-a Furniture
  - why: easier way to define new class based on existing class, polymorphism
  - base class: super class, parent class, existing class, general
  - derived class: subclass, child class, new class, specific
    - inherite member data & functions from base class (not constructors/destructor)
    - define new member data & functions
    - redefine member functions inherited from base class

*/

//base class
class Rectangle{
// private:
protected: //member access specifier - derived class can access them
  double width, length;

public:
  Rectangle(double w = 1.0, double l = 1.0): width(w), length(l) {}
  double getArea() const { return width * length; }
  void print() const {
    cout << "Rectangle: " << width << " x " << length << endl;
  }
};

//derived class
class Cube : public Rectangle { //public - class access specifier
private:
  //have width & length
  double height;

public:
  Cube(double w, double l, double h): Rectangle(w, l), height(h) {} //call parameterized base constructor
  double getVolume() const { return getArea() * height; }  
  //redefine base function print()
  void print() const {
    cout << "Cube with base: ";
    Rectangle::print();
    cout << "Height: " << height << endl;
  }
};

/*
2. Polymorphism
  - what: "many forms", objects of diff types behave differently with same function
  - why: when program extended, no change to existing code
  - how: 1) inheritance; 2) dynamic binding; 3) type declaration

+ Binding: how cpp determine/match the function to be called
  - static binding: compilation-time binding
  - dynamic binding: runtime binding
    - virtual base functions - overriding

+ virtual:
  - base functions defined to be virtual
    - pure virtual function: only header = 0, no body
      - abstract base class: has 1+ pure virtual functions, can't be instantiated
  - override/redefine virtual functions in derive classes
    - add "override" to derived function
    - add "final" to stop overriding 
  - base class has virtual destructor

*/

//base class
class Animal {
protected:
  string name;

public: 
  Animal(string n): name(n) {}
  virtual void speak() const { cout << "Animal " << name << " is speaking...\n"; }
  virtual void eat() const = 0; //pure virtual function
  virtual ~Animal() {}
};

//derived class 1
class Dog: public Animal{
private:
  int age;
public:
  Dog(string n, int a): Animal(n), age(a) {}
  void speak() const override { cout << "Dog " << name << ": WooWoo...\n"; }
  void eat() const override { cout << "Dog " << name << " is eating...\n"; }
  void swim() const { cout << "Dog " << name << " is swimming...\n"; }
};

//derived class 2
class Cat: public Animal{
private:
  string color;
public:
  Cat(string n, string c): Animal(n), color(c) {}
  void speak() const override { cout << "Cat " << name << ": MiaoMiao...\n"; }
  void eat() const override final { cout << "Cat " << name << " is eating...\n"; }
  void climb() const { cout << "Cat " << name << " is climbing...\n"; }
};

void animalPlay(Animal* animals[], int size) {
  for (int i = 0; i < size; i++) {
    animals[i]->speak();
    animals[i]->eat();
  }
}

int main() {
  Cube c1(1.2, 2.3, 3.4);
  c1.print();
  cout << "Base area: " << c1.getArea() << " and volume: " << c1.getVolume() << endl;

  Animal* a1 = new Dog("Monday", 3); //declared type = animal, actual type = dog
  a1->speak(); 

  Animal* as[] = {new Dog("Spiderman", 3), new Cat("MiMi", "Yellow"),
                  new Dog("WildWolf", 5), new Cat("King", "White")};
  animalPlay(as, sizeof(as) / sizeof(as[0]));

}


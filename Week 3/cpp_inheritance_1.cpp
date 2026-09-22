#include <iostream>
#include <string>

using namespace std;

/*
1. Inheritance
    - What: strongest relationship, IS-A
    Student is-a Person, Car is-a Vehicle, Flower is-a Plant, Chair is-a Furniture
    - Why: Easiest way to define new class based on existing class, polymorphism.
    - base class: super class, parents class, existing class, general.
    - derived class: subclass, child class, new class, specific.
    - inhereite member data & functions from base class (not constructors/deconstructors)
    - define new member data & functions


*/

class Rectangle{
    private:
        double width, length;
    public:
        Rectangle(double w = 1.0, double l = 1.0): width(w), length(l){};

        double getArea() const{
            return width * length;
        }

        void print() const{
            cout << "Rectangle: " << width << "x " << length << endl;
        }

};

class Cube:public Rectangle{
    private:
        double height;
    public:
        Cube(double w, double l, double h): Rectangle(w, l), height(h){};

        double getVolume() const {
            return getArea() * height;
        }

        void print() const{
            cout << "Cube with base: ";
            Rectangle::print();
            cout << "Height: " << height << endl;
        }


};

int main(){

    Cube c1(1.2, 2.3, 3.4);
    c1.print();
    cout << "Base areaL " << c1.getArea() << " and volume: " << c1.getVolume() << endl;

    return 0;
}
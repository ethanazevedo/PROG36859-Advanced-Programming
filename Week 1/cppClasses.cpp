#include <iostream>
using namespace std;


/*
- OOP (object-oriented programming), VS procedural programming.
- Encapulation, class, object
- Attributes, methods, UML class diagram
- Access specifiers, (public, private, protected), scope resolution operator (::)
- Declaration, definition, inside class, outside class.
- Constructor, destructor
*/

const double PI = 3.14159;

class Circle {
    private: 
        double radius;
        string color;
    public:
        Circle(): radius(1.0), color("red") {} //no-arg constructor, use this as prefered
        Circle(double r, string c): radius(r), color(c) {} //all-arg constructor
        Circle(double r): Circle(r, "red") {} //constructor delegation

        double getRadius() const { return radius; }
        string getColor() const { return color; }
        double getArea() const { return PI * radius * radius; }

        void setRadius(double r) { radius = r; }
        void setColor(string c = "Blue");

        void print() const{
            cout << "Circle(" << radius << ", " << color << ")\n";
        }

        ~Circle() {} //destructor
};

void Circle::setColor(string c) {
    color = c;
}

double getTotalArea(const Circle* ca, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++){
        total += ca[i].getArea();
    }
    return total;
}

int main() {
    
    Circle c1, c2 (2.1, "Red"), c3(3.4), c4{4.5};
    c2.print();

    Circle ca1[]{{}, {5.5, "Yellow"}, {4.4}};
    for (const auto& c : ca1) { //range-based for loop
        c.print();
    }

    int size = sizeof(ca1) / sizeof(ca1[0]);
    for (int i = 0; i < size, i++){
        ca1[i].print();
    }


    Circle* cp1 = &c1;
    cp1->print();

    Circle* cp2 = new Circle[]{c1, c2, c3, c4, Circle{}, {3.4, "Green"}}; //dynamic arrauy on heap
    for (int i = 0; i < 6; i++){
        cp2[i].print();
    }


    double a1 = getTotalArea(ca1,size);
    double a2 = getTotalArea(cp2, 6);
    cout << "Areas: " << a1 << " and " << a2 << endl;

    delete[] cp2; //like free in C






    cout << "Hello, World!";
    return 0;
}   

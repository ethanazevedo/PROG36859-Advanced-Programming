/* Names: Ethan Azevedo, Simon Clifford, Lucas Mahler
* Class: PROG36859
* Assignment: Assignment #1
* Date: October 9th, 2026
* Program: assignment1_azevedo.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = 3.14159; 

// TODO#1 - Abstract base class Shape

class Shape{
    protected:
        string type;
        string color;
    public:
        Shape(const string& t = "None", const string& c = "None"): type(t), color(c){};

        //Returns the color of the shape.
        string getColor() const{ 
            return color;
        }

        //Updates the color of the shape.
        void setColor(const string& newColor){
            color = newColor;
        }

        virtual double getArea() const = 0;
        virtual void printInfo() const = 0;

        //comparing shapes based on area for sorting later.
        bool operator<(const Shape& other){
            return getArea() < other.getArea();
        }

        //destructor
        virtual ~Shape(){
            nullptr;
        }
};

// TODO#2 - Concrete subclass Triangle

class Triangle : public Shape{
    private: 
        double base;
        double height;
    public:
        Triangle(double b = 1.0, double h = 1.0, const string& t = "Triangle", 
                    const string& c = "White"): base(b), height(h), Shape(t, c){};
        
        // Calculates and returns the area of the triangle.
        double getArea() const override {
            return 0.5 * base * height;
        }

        // Displays triangle info.
        void printInfo() const override{
            cout << "Type: " << Shape::type << ", Color: " << Shape::color 
            << ", Base: " << base << ", Height: " << height << ", Area: " << getArea() << endl;
        }
};

// TODO#3 - Concrete subclass Circle

class Circle : public Shape{
    private: 
        double radius;
    public: 
        Circle(double r = 1.0, const string& t = "Circle", 
                const string& c = "White"): radius(r), Shape(t, c){};

        // Calculates and returns the area of the circle.
        double getArea() const override {
            return PI * radius * radius;
        }

        // Display circle info.
        void printInfo() const override{
            cout << "Type: " << Shape::type << ", Color: " << Shape::color 
            << ", Radius: " << radius << ", Area: " << getArea() << endl;
        }
};

int main() {
    // TODO#4.1 - Create a vector of 3 triangles
    //            Sort triangles by area and color

    vector<Triangle> triangles = {
        Triangle(),
        Triangle(5.4, 7.6, "Triangle", "Red"),
        Triangle(6.5, 4.3, "Triangle", "Blue"),
    };

    sort(triangles.begin(), triangles.end());
    cout << "=== Triangles sorted by area:" << endl;
    for (const auto& t : triangles) t.printInfo();

    sort(triangles.begin(), triangles.end(), [](const Triangle& a, const Triangle& b) {
        return a.getColor() < b.getColor();
    });
    cout << "\n=== Triangles sorted by color:" << endl;
    for (const auto& t : triangles) t.printInfo();

    // TODO#4.2 - Create a vector of 3 circles
    //            Sort circles by area and color

    vector<Circle> circles = {
        Circle(),
        Circle(2.34, "Circle", "Yellow"),
        Circle(1.23, "Circle", "Green"),
    };

    sort(circles.begin(), circles.end());
    cout << "\n=== Circles sorted by area:" << endl;
    for (const auto& c : circles) c.printInfo();

    sort(circles.begin(), circles.end(), [](const Circle& a, const Circle& b) {
        return a.getColor() < b.getColor();
    });
    cout << "\n=== Circles sorted by color:" << endl;
    for (const auto& c : circles) c.printInfo();

    // Bonus (2 marks): 
    // TODO#4.3 - Create a vector of 6 shape pointers
    //            Sort all shapes by area and color

    vector<Shape*> shapes = {
        &triangles[0],
        &triangles[1],
        &triangles[2],
        &circles[0],
        &circles[1],
        &circles[2],
    };

    cout << "\n=== Merged shapes:" << endl;
    for (const auto& s : shapes) s->printInfo();

    sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->getArea() < b->getArea();
    });
    cout << "\n=== Shapes sorted by area:" << endl;
    for (const auto& s : shapes) s->printInfo();

    sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->getColor() < b->getColor();
    });
    cout << "\n=== Shapes sorted by color:" << endl;
    for (const auto& s : shapes) s->printInfo();

    return 0;
}
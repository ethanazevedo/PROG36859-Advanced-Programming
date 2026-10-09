/* Name: Ethan Azevedo, Simon Clifford, Lucas Mahler
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

        string getColor(){
            return color;
        }

        void setColor(const string& newColor){
            color = newColor;
        }

        virtual double getArea() const = 0;
        virtual void printInfo() const = 0;

        bool operator<(const Shape& other){
            return getArea() < other.getArea();
        }

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
        double getArea() const override {
            return 0.5 * base * height;
        }
        void printInfo() const override{
            cout << "Type: " << Shape::type << ", Color: " << Shape::color << ", Base: " << base << ", Height: " << height << ", Area: " << getArea();
        }
};

// TODO#3 - Concrete subclass Circle

class Circle : public Shape{
    private: 
        double radius;
    public: 
        Circle(double r = 1.0, const string& t = "Circle", 
                const string& c = "White"): radius(r), Shape(t, c){};

        double getArea() const override {
            return PI * radius * radius;
        }
        void printInfo() const override{
            cout << "Type: " << Shape::type << ", Color: " << Shape::color << ", Radius: " << radius << ", Area: " << getArea();
        }
};

int main() {
    // TODO#4.1 - Create a vector of 3 triangles
    //            Sort triangles by area and color

    vector<Triangle> triangles = {
        Triangle(5.0, 4.0, "Triangle", "Red"),
        Triangle(3.0, 6.0, "Triangle", "Blue"),
        Triangle(8.0, 2.0, "Triangle", "Green"),
    };

    


    // TODO#4.2 - Create a vector of 3 circles
    //            Sort circles by area and color
    
    // Bonus (2 marks): 
    // TODO#4.3 - Create a vector of 6 shape pointers
    //            Sort all shapes by area and color
}
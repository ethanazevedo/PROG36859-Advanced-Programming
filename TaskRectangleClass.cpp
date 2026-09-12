#include <iostream>
using namespace std;


class Rectangle{
    private:
        double length;
        double width;
    public: 
        Rectangle(): length(1), width(1) {};
        Rectangle(double l, double w): length(l), width(w) {};

        double getArea(){
            double s = length*width;
            return s;
        };

        double getPerimeter(){
            double p = 2*(length+width) ;
            return p;
        };



};

int main(){

    Rectangle r1;
    Rectangle r2(4, 3);

    cout << r1.getArea() << endl;
    cout << r1.getPerimeter() << endl;
    
    cout << r2.getArea() << endl;
    cout << r2.getPerimeter() << endl;

    return 0;


}
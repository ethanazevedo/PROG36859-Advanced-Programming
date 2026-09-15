#include <iostream>
using namespace std;


class Circle{
    private:
        double radius;
        string color;
    public:
        Circle();
        Circle(double d, string c);


        double getRadius() const {
            return radius;
        }
        void setRadius(double d) {
            radius = d;
        }
        void print(){
            cout << "Circle: " << radius << ", " << color << "\n ";
        }


};


int main() {


    return 0;
}
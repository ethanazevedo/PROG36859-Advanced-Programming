#include <iostream>
using namespace std;

class Car{
    private:
        string brand;
        string model;
        int year;
        double speed;
    public:
        Car();
        Car(string b, string m, int y): brand(b), model(m), year(y) {};

        double getSpeed(){
            return speed;
        }
        
        void accelerate(double s){
            speed = speed + s;
        }

        void brake(double s){
            speed = speed - s;
        }

        void print(){
            cout << "Car: " << year << ", " << brand << ", " << model << ", " << speed << ", " << "\n ";
        }





};

int main(){

    Car c1("Volkswagen", "Tiguan", 2022);

    c1.accelerate(40);

    c1.print();
    

    return 0; 
}
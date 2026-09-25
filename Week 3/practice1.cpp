#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Vehicle{
    protected:
        string brand;
    public:
        Vehicle(string b): brand(b) {};

        virtual void start() const = 0;
};

class Car : public Vehicle{
    public:
        Car(string b): Vehicle(b) {};

        void start() const override{
            cout << "Starting Car..." << endl;
        }
};

class Motorcycle : public Vehicle{
    public:
        Motorcycle(string b): Vehicle(b) {};

        void start() const override{
            cout << "Starting MotorCycle..." << endl;
        }
};


int main(){

Vehicle* vehicles[] = {

    new Car("Toyota"),
    new Motorcycle("Superbike")
};

    for(int i = 0; i < 2; i++){
        vehicles[i]->start();
    };

return 0;
};
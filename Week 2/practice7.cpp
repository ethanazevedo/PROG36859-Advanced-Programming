#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Employee{
    private: 
        string name;
        double* hours;
        static double totalHours;

    public:
        Employee(string n, double reg, double ove): name(n){

            hours = new double[2];

            hours[0] = reg;
            hours[1] = ove;

            totalHours += hours[1];

        }

        Employee(const Employee& other){

            name = other.name;
            hours = new double[2];

            hours[0] = other.hours[0];
            hours[1] = other.hours[1];

            totalHours += hours[1];
        }

        Employee& operator=(const Employee& other){
            if(this != &other){
                
                totalHours -= hours[1];
                name = other.name;

                delete[] hours;
                
                hours = new double[2];

                hours[0] = other.hours[0];
                hours[1] = other.hours[1];

                totalHours += hours[1];

            }
            return *this;
        }

        double hoursTotal() const{
            return hours[0] + hours[1];
        }

        bool operator<(const Employee& other){
            return hoursTotal() < other.hoursTotal();
        }

        friend void displayEmployee(const Employee& p);

        ~Employee(){
            delete[] hours;
        }

};


double Employee::totalHours = 0;

void displayEmployee(const Employee& p){
    cout << "Employee Name: " << p.name << endl;


}



int main(){

    Employee e1("Ethan", 20, 5);
    Employee e2("Fwanda", 40, 10);
    Employee e3(e1);

    e2=e1;

    if(e1<e2){
        cout << "Hello! " << endl;
    }
    else
        cout << "Bye! " << endl;


    displayEmployee(e1);
    displayEmployee(e2);
    displayEmployee(e3);




    return 0;
}
#include <iostream>
using namespace std; 


class Dog{
    private:
        string name;
        int age;
    public: 
        Dog(string n, int a): name(n), age(a){};

        void bark(){
            cout << "\n Woof \n";
        };
        
        int getAge(){
            return age;
        }
};


int main(){

    Dog d1("Jeffery", 67);
    Dog d2("Joe", 1);

    cout << d1.getAge();
    d1.bark();
    


    return 0; 
}
#include <iostream>
#include <string>
#include <memory>

using namespace std;


/*
1. Static member data:
- Instance member data: belongs to objects.
- static member data: belongs in class, shared by all objects.
- initialized outside class.
- static memeber function can only access static data.
- recommended to be called using class.


2. Friend of a Class:
- Declare a function, a class, a class member function to be the friend of a lass.
- Can access private member data of the class outside the class. 

3. Operator Overloading:
- redefine standard operators behaviour, use with objects: +, -, *, <, =, >, <=, >=, ...
- like magic method in python: __add/gt/eq/ne/lt__



*/
class Pet {
    private: 
        int age;
        string name;
        static int count;

    public:
        Pet(int a = 1, string n = "Unknown"): age(a), name(n){ count++; };
        ~Pet() {count--;};

        void print() const{
            cout << "Pet: " << age << ", " << name << endl;

        }

        static int getCount(){
            return count;
        }


        friend void updatePet(Pet&, int, string);

        bool operator<(const Pet& other){
            return age < other.age;

        }


};


int Pet::count = 0; //initilize a static member data

void updatePet(Pet& p, int a, string n){
    p.age = a;
    p.name = n;

}



/*
Copy:



*/


class Buffer{
    private:
        int size;
        string* contents;

    public:
        Buffer(int s): size(s){
            contents = new string[size]; //dynamic array of strings. 
        }

        ~Buffer(){
            delete[] contents;
            contents = nullptr;
        }


        void insert (int i, string s){
            if (i >= 0 && i < size)
                contents[i] = s;
        }


        void print() const{
            cout << "Buffer contents: ";
            for (int i = 0; i < size; i++)
                cout << contents[i] << ", ";
            cout << endl;
            
        }



//copy constructor
Buffer(const Buffer& other): size(other.size){
    contents = new string[size];
    for(int i = 0; i < size; i++)
        contents[i] = other.contents[i];
    
}





//copy assignment (overloading = )

Buffer& operator=(const Buffer& other){
    //this is a pointer to the current object

    if (this != &other){
        size = other.size;
        delete[] contents;
        contents = new string[size];
        for(int i = 0; i < size; i++)
            contents[i] = other.contents[i];
}
return *this;
}


        
};


int main(){


    Pet p1{2, "WooWoo"}, p2{3, "MeowMeow"}, p3{7, "DingDing"};

    p2.print();

    cout << "Number of pets: " << Pet:: getCount() << endl;


    {
        Pet pa[100];
        cout << "Number of pets: " << Pet:: getCount() << endl;

    }

        cout << "Number of pets: " << Pet:: getCount() << endl;


        updatePet(p3, 8, "Dung Dung");
        p3.print();


        if (p1 < p2){
            cout << "Pet1 is less than Pet2 in terms of age" << endl;
        }




        Buffer b1(10);
        for (int i = 0; i < 10; i++)
            b1.insert(i, "Hello" + to_string(i));
        b1.print();

        Buffer b2=b1;
        b1.insert(0, "world");
        b2.print();
        b2 = b1;
        b2.print();



    return 0;
}
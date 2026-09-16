#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Container{
    private: 
         double* measurements;
    public: 
        Container(double l, double w, double h){

            measurements = new double[3];

            measurements[0] = l;
            measurements[1] = w;
            measurements[2] = h;
        }

        Container(const Container& other){
            measurements = new double[3];

            measurements[0] = other.measurements[0];
            measurements[1] = other.measurements[1];
            measurements[2] = other.measurements[2];
        }

        Container& operator=(const Container& other){
            if(this != &other){
                delete[] measurements;

                measurements = new double[3];

                measurements[0] = other.measurements[0];
                measurements[1] = other.measurements[1];
                measurements[2] = other.measurements[2];

            }
            return *this;
        }

        bool operator<(const Container& other){
            return totalSize() < other.totalSize();
        }


        ~Container(){
            delete[] measurements;
        }


        double totalSize() const{
            return measurements[0] + measurements[1] + measurements[2];
        }

};

int main(){
    
    
    Container c1(1, 7, 3);
    Container c2(c1);

    Container c3(3, 4, 1);
    //c3 = c1;

    cout << c1.totalSize() << endl;
    cout << c2.totalSize() << endl;
    cout << c3.totalSize() << endl;

    if (c3 < c2){
        cout << "hello this works lol " << endl;
    }






    return 0;
}
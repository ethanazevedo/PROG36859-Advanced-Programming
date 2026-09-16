#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Box{
    private: 
        double* dims;
    public:
        Box(double l, double w, double h){
            dims = new double[3];

            dims[0] = l;
            dims[1] = w;
            dims[2] = h;
        }

        Box(const Box& other){
            dims = new double[3];

            dims[0] = other.dims[0];
            dims[1] = other.dims[1];
            dims[2] = other.dims[2];
        }

        Box& operator=(const Box& other){
            if (this != &other){
                delete[] dims;

                dims = new double[3];

                dims[0] = other.dims[0];
                dims[1] = other.dims[1];
                dims[2] = other.dims[2];
            }
            return *this;
        }

        bool operator<(const Box& other){
            return volume() < other.volume();
        }

        double volume() const{
            return dims[0] * dims[1] * dims[2];
        }



        ~Box(){
            delete[] dims;
        }




        



};



int main(){

    Box b1(2, 3, 3);
    Box b2(4, 5, 4);
    Box b4(1, 1, 1);

    Box b3(b1);
    b4 = b2;

    cout << b1.volume() << endl;
    cout << b2.volume() << endl;
    cout << b3.volume() << endl;

    if (b1 < b2){
        cout << "Hello there it works! " << endl;
    }

    return 0; 
}
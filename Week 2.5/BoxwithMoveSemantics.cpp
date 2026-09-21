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
            /*
            dims[0] = other.dims[0];
            dims[1] = other.dims[1];
            dims[2] = other.dims[2];
            */

            for(int i = 0; i < 3; i++){
                dims[i] = other.dims[i];
            }

        }


        Box& operator=(const Box& other){
            if (this != &other){
                delete[] dims;

                dims = new double[3];
                /*
                dims[0] = other.dims[0];
                dims[1] = other.dims[1];
                dims[2] = other.dims[2];
                */

                for(int i = 0; i < 3; i++){
                    dims[i] = other.dims[i];
                }
            }

            return *this;
        }


 // Move constructor
        Box(Box&& other){
            dims = other.dims;

            other.dims = nullptr;
        }


// Move assignment
        Box& operator=(Box&& other){
            if(this != &other){
                delete[] dims;

                dims = other.dims;

                other.dims = nullptr;
            }

            return *this;
        }




        bool operator<(const Box& other) {
            return volume() < other.volume();
        }



        ~Box(){
            delete[] dims;
        }

        double volume() const{
            return dims[0] * dims[1] * dims[2];
        }


};


int main(){

    Box b1(10, 5, 2);

    Box b2(b1);

    Box b3(2, 3, 4);

    b2 = b1;

    cout << b1.volume() << endl;
    cout << b2.volume() << endl;
    cout << b3.volume() << endl;

     if (b1 < b2){
        cout << "Hello there it works! " << endl;
    }

    return 0;
}
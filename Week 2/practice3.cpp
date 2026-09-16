#include <iostream>
#include <string>
#include <memory>

using namespace std;

class StorageUnit{
    private: 
        double* dimensions;
    public:
        StorageUnit(double l, double w, double h){
            dimensions = new double[3];

            dimensions[0] = l;
            dimensions[1] = w;
            dimensions[2] = h;
        }


        StorageUnit(const StorageUnit& other){
            dimensions = new double[3];

            dimensions[0] = other.dimensions[0];
            dimensions[1] = other.dimensions[1];
            dimensions[2] = other.dimensions[2];

        }

        StorageUnit& operator=(const StorageUnit& other){
            if (this != &other){
                delete[] dimensions;

                dimensions = new double[3];

                dimensions[0] = other.dimensions[0];
                dimensions[1] = other.dimensions[1];
                dimensions[2] = other.dimensions[2];
            }
            return *this;
        }

        bool operator<(const StorageUnit& other){
            return volume() < other.volume();

        }


        ~StorageUnit(){
            delete[] dimensions;
        }


        double volume() const{
            return dimensions[0] * dimensions[1] * dimensions[2];
        }

};



int main(){





    return 0;
}
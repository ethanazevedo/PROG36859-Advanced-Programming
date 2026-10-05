#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box{
    private: 
        T minVal;
        T maxVal;
    public:
        Box(T mi, T ma): minVal(mi), maxVal(ma){
            if(minVal == maxVal)
                throw string("Values cannot be the same. ");
        }

        void add(T value) {
            if(value < minVal)
                minVal = value;
            else if(value > maxVal)
                maxVal = value;
        }

        void print() const{
            cout << "Current min: " << minVal << ", " << "Current max: " << maxVal << endl;
        }


};

int main(){


    try{
        Box b1(1, 5);

        b1.print();
        b1.add(23);
        b1.print();
    }
    catch(const string& e){
        cout << e << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

class Container{
    private:
        double* data;
    public:

        Container(double a, double b, double c, double d){

            data = new double[4];

            data[0] = a;
            data[1] = b;
            data[2] = c;
            data[3] = d;
        }

        Container(const Container& other){
            data = new double[4];

            for(int i = 0; i < 4; i++){
                data[i] = other.data[i];
            }
        }

        Container& operator=(const Container& other){
            if (this != &other){
                delete[] data;

                data = new double[4];
                for(int i = 0; i < 4; i++){
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        Container(Container&& other){
            data = other.data;

            other.data = nullptr;



        }

        Container& operator=(Container&& other){
            if (this != &other){
                delete[] data;

                data = other.data;

                other.data = nullptr;
            }
            return *this;
        }


        double sum() const{
            return data[0] + data[1] + data[2] + data[3];
        }

        bool operator<(const Container& other){
            return sum() < other.sum();
        }

        ~Container(){
            delete[] data;
            data = nullptr;
        }



};



int main(){

    Container c1(1, 2, 3, 4);

    Container c2(c1);

    Container c3 = c1;

    Container c4 = Container(2, 3, 4 , 6);

    Container c5(1, 1, 1, 1);
    c5 = Container(50, 60, 70, 80);

    cout << "c1: " << c1.sum() << endl;
    cout << "c2: " << c2.sum() << endl;
    cout << "c3: " << c3.sum() << endl;
    cout << "c4: " << c4.sum() << endl;
    cout << "c5: " << c5.sum() << endl;



    return 0;


}
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Die{
    private:
        int sides;
        char* labels;


    public:
        Die(int s = 6): sides(s), labels(new char[s]){};


        void set(int i, char c){ 
            labels[i] = c;
        }

        void print() const{
            cout << "Die: ";
            for (int i = 0; i < sides; i++){
                cout << labels[i] << " ";
            }
            cout << endl;

        }


        ~Die(){
            delete[] labels;
        }

        Die(const Die& d): sides(d.sides), labels(new char[d.sides]){
            for(int i = 0; i < sides; i++){
                labels[i] = d.labels[i];
            }
        }

        Die& operator=(const Die& d){
            if (this != &d){
                delete[] labels;
                sides = d.sides;
                labels = new char[sides];
                for(int i = 0; i < sides; i++){
                    labels[i] = d.labels[i];
                }
            }
            return *this;
        }



        //move constructor
        Die(Die&& d){
            sides = d.sides;
            labels = d.labels;

            d.sides = 0;
            d.labels = nullptr;
        }

        Die& operator=(Die&& d){
            if (this != &d){
                delete[] labels;
                sides = d.sides;
                labels = d.labels;

                d.sides = 0;
                d.labels = nullptr;
            }
            return *this;
        }



};



int main(){

    Die d1(10);

    for (int i = 0; i < 10; i++){
        d1.set(i, 'A' + i);
    }
    d1.print();

    Die d2 = d1;
    Die d3;
    d3 = d1; 

    d2.print();
    d3.print();

    /*Lvalue and Rvalue.
    - Lvalue: named value, left of =
    - Rvalue: temporary value, right of =
    */

    int x = 10 + 33; //X is Lvalue, 10 + 33 is an R(right)value.
    int y = x + 123;

    //Lvalue reference and Rvalue reference
    int& xr = x; //xr Lvalue reference
    int&& rr = x + 100; //rr Rvalue reference

    //move
    //- transfers a source (temporary) to the target (nammed)
    //remove the need of unnecessary copy
    Die d4 = Die(); //move constructor
    d4 = Die(10); //move assignment


    return 0;
}
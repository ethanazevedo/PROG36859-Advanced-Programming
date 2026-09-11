#include <iostream>
using namespace std;

class Product{
    private: 
        int id;
        string name;
        double price;
        int amount;
    public:
        Product();
        Product(int id, string name, double price, int amount): id(id), name(name), price(price), amount(amount){};

        int getId(){
            return id;
        };

        string getName(){
            return name;
        };

        double getPrice(){
            return price;
        };

        int getAmount(){
            return amount;
        };

        void setId(int i){
            id = i
        };

        void setName(string n){
            name = n;
        };


};

int main(){

    return 0;
}
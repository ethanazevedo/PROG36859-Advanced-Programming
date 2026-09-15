#include <iostream>
using namespace std;

class Product{
    private: 
        int id;
        string name;
        double price;
        int amount;
    public:
        Product(): id(0), name(""), price(0.0), amount(0) {};
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
            id = i;
        };

        void setName(string n){
            name = n;
        };

        void setPrice(double p){
            price = p;
        };

        void setAmount(int a){
            amount = a;
        };

        void print(){
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Price: " << price << endl;
            cout << "Amount: " << amount << endl;
        };

};

int main(){

    Product p1;
    Product p2(124, "Banana", 2.79, 1);

    cout << p2.getId() << endl;
    cout << p2.getName() << endl;
    cout << p2.getPrice() << endl;
    cout << p2.getAmount() << endl << endl;

    p1.setId(456);
    p1.setName("Strawberry");
    p1.setPrice(1.99);
    p1.setAmount(8);

    p1.print();

    return 0;
}
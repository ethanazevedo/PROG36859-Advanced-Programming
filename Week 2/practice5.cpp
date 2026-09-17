#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Product{
    private:
        string name;
        double* prices;
        static double totalValue;
    public:
        Product(string n, double regular, double sale): name(n) {

            prices = new double[2];

            prices[0] = regular;
            prices[1] = sale;

            totalValue += sale;

        }

        Product(const Product& other){

            prices = new double[2];

            prices[0] = other.prices[0];
            prices[1] = other.prices[1];

            totalValue += prices[1];

        }



        Product& operator=(const Product& other){
            if (this != &other){
                totalValue -= prices[1];

                delete[] prices;

                prices = new double[2];

                prices[0] = other.prices[0];
                prices[1] = other.prices[1];

                totalValue += prices[1];

            }
        return *this;
        }



        double totalPrice() const{
            return prices[0] + prices[1];
        }




        bool operator<(const Product& other){
            return totalPrice() < other.totalPrice();
        }


        friend void displayProduct(const Product& p);

        ~Product(){
            delete[] prices;
        }


};

double Product::totalValue = 0;

void displayProduct(const Product& p){
    cout << "Product: " << p.name << endl;
    cout << "Regular Price: " << p.prices[0] << endl;
    cout << "Sale Price: " << p.prices[1] << endl;
    cout << "Total Value of All Products: " << Product::totalValue << endl;

}


int main(){

    Product p1("Banana" , 5.99, 4.99);
    Product p2("Oranges", 12.99, 9.99);

    Product p3(p1);    // copy constructor

    p2 = p1;           // assignment operator

    displayProduct(p1);
    displayProduct(p2);
    displayProduct(p3);

    if (p1 < p2) {
        cout << "Hello there! " << endl;
    }



    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class BankAccount{
    private:
        double balance;
    public:
        BankAccount(double b): balance(b) {};

        void withdraw(double amount){
            if(amount > balance){
                throw string("Withdrawl is greater than balance ");
            }
        }


};


int main(){

    BankAccount b1(250);

    try{
        b1.withdraw(750);
    }
    catch (string const& e){
        cout << e << endl;
    }

    cout << "Transaction Complete " << endl;


    return 0;
}
#include <iostream>
using namespace std;


class BankAccount{
    private:
        string accountNumber;
        double balance;
    public:
        BankAccount(): accountNumber("0000"), balance(0.0) {};
        BankAccount(string a, double b): accountNumber(a), balance(b) {}; 

        void deposit(double amount){
            balance = balance + amount;
        };

        void withdraw(double amount){
            if (balance > amount){
                balance = balance - amount;
            }
        };

        void Display(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        };

};



int main(){

    BankAccount b1;
    BankAccount b2("1234", 100);

    b1.deposit(100);
    b2.deposit(100);

    b1.withdraw(10);
    b2.withdraw(20);

    b1.Display();
    b2.Display();




    return 0;
}
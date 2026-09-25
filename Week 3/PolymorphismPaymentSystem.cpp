/*
2 – Polymorphism (Payment System): 

Create an abstract base class Payment with a pure virtual function processPayment(). 

Create derived classes: 
CreditCardPayment – prints "Processing credit card payment of $amount" 
PayPalPayment – prints "Processing PayPal payment of $amount" 

In main(), store different payment objects in an array of Payment* and call processPayment() 
to demonstrate runtime polymorphism.

*/


#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Payment{
    protected:
        double amount;
    public:
        Payment(double a): amount(a) {};

        virtual void processPayment() const = 0;
};

class CreditCardPayment : public Payment{
    public:
        CreditCardPayment(double a): Payment(a){};

        void processPayment() const override {
            cout << "Processing credit card payment of " << Payment::amount << endl;
        }
};

class PayPalPayment : public Payment{
    public:
        PayPalPayment(double a): Payment(a){};

        void processPayment() const override {
            cout << "Processing PayPal payment of " << Payment::amount << endl;
        }
};




int main(){

    Payment* payments[] = {
        new CreditCardPayment(250),
        new PayPalPayment(350),
        new CreditCardPayment(450)
    };

    for (int i = 0; i < 3; i++) {
        payments[i]->processPayment();
    }

    return 0;
}
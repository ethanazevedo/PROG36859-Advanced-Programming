/*
4 – Polymorphism (Notification System)

Create an abstract base class Notification with a pure virtual function send().

Create derived classes:

EmailNotification – prints "Sending email notification"
SMSNotification – prints "Sending SMS notification"

The base class should also have a recipient member.

In main(), create an array of Notification* containing different notification objects and 
call send() on each object to demonstrate runtime polymorphism.
*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Notification{
    protected:
        string recipient;
    public:
        Notification(string r): recipient(r) {};
        
        virtual void send() const = 0;
};

class EmailNotification : public Notification{
    public:
        EmailNotification(string r): Notification(r) {};

        void send() const override{
            cout << "Sending email notification " << Notification::recipient << endl;
        }

};

class SMSNotifiation : public Notification{
    public:
        SMSNotifiation(string r): Notification(r) {};

        void send() const override{
            cout << "Sending email notification " << Notification::recipient << endl;
        }
};



int main(){

    Notification* messages[] = {
        new EmailNotification("Ethan"),
        new SMSNotifiation("Fwanda"),
        new EmailNotification("Joe")
    };

    for(int i = 0; i < 3; i++){
        messages[i]->send();
    }

    return 0;
}
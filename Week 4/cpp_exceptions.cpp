#include <iostream>
#include <string>
#include <exception>

using namespace std;

/*
Exceptions:
- what: a run-time error or event, program crash if not handled
- an exception is "thrown"

1. try/catch (like try/except in Python)
  try {
    normal code (may throw exceptions)
  } catch(an exception) {
    exception handling code
  }
  - one try can have multiple catch
  - catch(exception): catch any standard exceptions
  - catch(...): catch any exception

2. throw (like raise in Python)
  - report an exception from a function
    throw exception_data;
  - exception data can be of any type
  - option 1: throw pre-existing standard exception
  - option 2: throw object of your own class (inner-class)
  - option 3: throw a custom exception 
    - define a derived class that inherite from exception class
    - override what() function: return c string
*/

class InsufficientFundsException : public exception {
private:
  double amount, balance;
  string msg;
public:
  InsufficientFundsException(double a, double b) : amount(a), balance(b) {
    msg = "Insufficient funds in withdraw, request=" + to_string(a) + ", balance=" + to_string(b);
  }

  const char* what() const noexcept override {
    return msg.c_str();
  }
};

class BankAccount {
private:
  string name;
  double balance;

public:
  //inner-class
  class BankAccountError {
  private:
    string msg;
  public:
    BankAccountError(string m) : msg(m) {}
    string getMsg() const { return msg; }
  };

  BankAccount(string n, double b) : name(n), balance(b) {
    //option 1
    if (b < 0) 
      throw invalid_argument("Initial deposit cannot be negative: " + to_string(b));
  }

  void deposit(double amount) {
    //option 2
    if (amount < 0)
      throw BankAccountError("Deposit amount cannot be negative: " + to_string(amount));

    balance += amount;
  }

  void withdraw(double amount) {
    if (amount < 0)
      throw BankAccountError("Deposit amount cannot be negative: " + to_string(amount));

    //option 3
    if (amount > balance)
      throw InsufficientFundsException(amount, balance);

    balance -= amount;
  }

};


int main() {
  try {
    BankAccount ba1("Superman", -123.45);
  } catch(const invalid_argument& e) {
    cerr << e.what() << endl;
  }

  try {
    BankAccount ba2("Thor", 100.00);
    ba2.deposit(-234.56);
  } catch(const BankAccount::BankAccountError& e) {
    cerr<< e.getMsg() << endl;
  }

  try {
    BankAccount ba3("Hulk", 1000);
    ba3.withdraw(2000);
  } catch(const InsufficientFundsException& e) {
    cerr << e.what() << endl;
  }

  try {
    string s1 = "abcxyz", s2 = "99999999999999999";
    int x = stoi(s1); //invalid_argument
    // int y = stoi(s2); //out_of_range

    string name = "Spiderman";
    // name.insert(100, "Parker"); //out_of_range

    int* ia = new int[9999999999]; //bad_alloc
  } catch(const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
  } catch(const out_of_range& e) {
    cerr << "Error: " << e.what() << endl;
  } catch(const bad_alloc& e) {
    cerr << "Error: " << e.what() << endl;
  } catch(const exception& e) {
    cerr << "Error: " << e.what() << endl;
  } catch(...) {
    cerr << "Error!\n";
  }

  cout << "I'm alive...\n";

}
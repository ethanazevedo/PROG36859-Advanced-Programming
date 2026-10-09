/*
Given the class Contact defined below, write two functions.

Function 1 – createContacts
- takes three parallel vector<string> objects: names, phones, emails.
- creates a vector<Contact> where each element is constructed from the 
  corresponding elements in the 3 input vectors. 
- returns the resulting vector<Contact>.
- Assume the 3 input vectors are valid and of the same size.

Function 2 – contactsToMap
- takes two vector<Contact> iterators (begin and end). 
- creates and returns a map<string, Contact> where the key is the 
  contact’s name and the value is the corresponding Contact object.

Note: Do NOT modify any provided code
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;

public:
    Contact() : Contact("", "", "") {}
    Contact(const string& name, const string& phone, const string& email)
        : name(name), phone(phone), email(email) {}

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }

    void print() const {
        cout << "Name: " << name
             << ", Phone: " << phone
             << ", Email: " << email << endl;
    }
};

//TODO#1
vector<Contact> createContacts(const vector<string>& names,
                               const vector<string>& phones,
                               const vector<string>& emails)
{
    vector<Contact> contacts;

    for (int i = 0; i < names.size(); i++) {
        contacts.push_back(Contact(names[i], phones[i], emails[i]));
    }


    return contacts;
}

//TODO#2

map<string, Contact> contactsToMap(const vector<Contact>::iterator begin,
                                   const vector<Contact>::iterator end)
{
    map<string, Contact> contactMap;

    for (auto it = begin; it != end; it++) {
        contactMap[it->getName()] = *it;
    }

    return contactMap;
}

/*
Expected output:
    == All Contacts in Vector:
    Name: Alice, Phone: 123-456-7890, Email: alice@example.com
    Name: Bob, Phone: 987-654-3210, Email: bob@example.com
    Name: Charlie, Phone: 555-555-5555, Email: charlie@example.com     

    == First Two Contact Map:
    Alice -> Name: Alice, Phone: 123-456-7890, Email: alice@example.com
    Bob -> Name: Bob, Phone: 987-654-3210, Email: bob@example.com 
*/
int main() {
    // Sample data
    vector<string> names  = {"Alice", "Bob", "Charlie"};
    vector<string> phones = {"123-456-7890", "987-654-3210", "555-555-5555"};
    vector<string> emails = {"alice@example.com", "bob@example.com", "charlie@example.com"};

    // Create contacts
    vector<Contact> contacts = createContacts(names, phones, emails);
    cout << "\n== All Contacts in Vector:\n";
    for (const auto& c : contacts) {
        c.print();
    }

    // Convert first 2 contacts to a map
    map<string, Contact> contactMap = contactsToMap(contacts.begin(), contacts.begin() + 2);
    cout << "\n== First Two Contact Map:\n";
    for (const auto& [name, contact] : contactMap) {
        cout << name << " -> ";
        contact.print();
    }
}

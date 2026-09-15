#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Book{
    private: 
        string title;
        int rating;
        static int totalRatings;
    public:
        Book(string n, int r): title(n), rating(r){ totalRatings+=r; };

        void addRating(int p){
            rating += p;
            totalRatings += p;
        }

        friend void displayBook(const Book& b);



};

int Book::totalRatings = 0;

void displayBook(const Book& b){
    cout << "Book: " << b.title << " Rating: " << b.rating << " Total Ratings: " << Book::totalRatings << endl;
}



int main(){


    Book b1("Harry Potter", 1);
    Book b2("Dune", 2);
    Book b3("The Hobbit", 3);

    b1.addRating(4);
    b2.addRating(3);
    b3.addRating(2);

    displayBook(b1);
    displayBook(b2);
    displayBook(b3);


    return 0;
}
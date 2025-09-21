#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    double price;

public:
    Book(string i = "", string t = "", string a = "", double p = 0.0) {
        isbn = i;
        title = t;
        author = a;
        price = p;
    }
    Book(const Book& b) {
        isbn = b.isbn;
        title = b.title;
        author = b.author;
        price = b.price;
    }
    void setISBN(string i) { isbn = i; }
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setPrice(double p) { price = p; }

    string getISBN() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }

    void applyDiscount(double percentage) {
        if (percentage > 0 && percentage <= 100) {
            price -= price * (percentage / 100);
        }
    }
    void display() {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};
int main() {
    Book b1("978-0140449198", "The Art of War", "Sun Tzu", 1500.0);

    b1.applyDiscount(10);
    b1.display();

    Book b2 = b1;
    b2.display();

    return 0;
}

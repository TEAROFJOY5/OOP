// Turab Ali 24k-0651
#include<iostream>
using namespace std;

class Stock {
    // Private attributes - sirf class ke andar access ho sakte hain
    string TickerSymbol;
    string CompanyName;
    double CurrentPrice;
    int QuantityOwned;

public:
    // Constructor - naya stock object banane ke liye
    Stock(string ticker, string name, double price, int qty) {
        TickerSymbol = ticker;
        CompanyName = name;
        CurrentPrice = price;
        QuantityOwned = qty;
    }

    // Copy Constructor - existing stock ka duplicate banane ke liye
    Stock(const Stock &s) {
        TickerSymbol = s.TickerSymbol;
        CompanyName = s.CompanyName;
        CurrentPrice = s.CurrentPrice;
        QuantityOwned = s.QuantityOwned;
    }

    // Setters - data set karne ke liye
    void setTicker(string ticker) { TickerSymbol = ticker; }
    void setCompany(string name) { CompanyName = name; }
    void setPrice(double price) { CurrentPrice = price; }
    void setQuantity(int qty) { QuantityOwned = qty; }

    // Getters - data read karne ke liye
    string getTicker() { return TickerSymbol; }
    string getCompany() { return CompanyName; }
    double getPrice() { return CurrentPrice; }
    int getQuantity() { return QuantityOwned; }

    // Method to calculate total value of stock holding
    double CalculateTotalValue() {
        return CurrentPrice * QuantityOwned;
    }

    // Stock ki details display karne ka method
    void Display() {
        cout << "Ticker Symbol: " << TickerSymbol << endl;
        cout << "Company Name: " << CompanyName << endl;
        cout << "Current Price (PKR): " << CurrentPrice << endl;
        cout << "Quantity Owned: " << QuantityOwned << endl;
        cout << "Total Holding Value (PKR): " << CalculateTotalValue() << endl;
    }
};

int main() {
    // Pehla stock object banaya
    Stock s1("TS", " Turab's Scent", 155.75, 100);  // 100 shares @ 155.75 PKR

    // Dusra stock, pehle wale ka duplicate
    Stock s2 = s1;

    // Dono stocks ki details display karte hain
    cout << "--- Original Stock (s1) ---" << endl;
    s1.Display();

    cout << "\n--- Duplicated Stock (s2) ---" << endl;
    s2.Display();

    return 0;
}

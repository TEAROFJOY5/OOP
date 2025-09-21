#include<iostream>
using namespace std;

class Wallet {
    // Private attributes hain
    int WalletID;
    string OwnerName;
    double Balance;
public:
    // Constructor - naya wallet banane ke liye
    Wallet(int id, string name, double bal) {
        WalletID = id;
        OwnerName = name;
        Balance = bal;
    }
    // Copy Constructor - kisi existing wallet ko copy karne ke liye
    Wallet(const Wallet &w) {
        WalletID = w.WalletID;
        OwnerName = w.OwnerName;
        Balance = w.Balance;
    }
    // Setters - private attributes ko set karne ke liye
    void setID(int id) { WalletID = id; }
    void setName(string name) { OwnerName = name; }
    void setBal(double bal) { Balance = bal; }
    // Getters - private attributes ko access karne ke liye
    int getID() { return WalletID; }
    string getName() { return OwnerName; }
    double getBal() { return Balance; }
    // Funds add karne ka method
    void AddFunds(double amount) {
        Balance += amount;
        cout << "Naya Balance (PKR): " << Balance << endl;
    }
    // Paise nikaalne ka method
    void Withdraw(double amount) {
        if (amount <= Balance) {
            Balance -= amount;
            cout << "Amount withdraw kar diya gaya. Remaining Balance (PKR): " << Balance << endl;
        } else {
            cout << "Insufficient balance, withdraw nahi ho saka." << endl;
        }
    }
    // Wallet ki details show karne ka method
    void Display() {
        cout << "Wallet ID: " << WalletID << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Balance (PKR): " << Balance << endl;
    }
};
int main() {
    // Pehla wallet banaya
    Wallet w1(1001, "Ali Khan", 10000);  // PKR 10,000
    // Dusra wallet, pehle wale ka duplicate
    Wallet w2 = w1;
    // Funds add aur withdraw kiya
    w1.AddFunds(1500);       // PKR 1,500 add kiye
    w1.Withdraw(2000);       // PKR 2,000 nikaale
    w2.Withdraw(12000);      // Zyada nikaalne ki koshish
    // Details show kar rahe hain
    cout << "\n--- Wallet 1 Details ---" << endl;
    w1.Display();
    cout << "\n--- Wallet 2 Details ---" << endl;
    w2.Display();
    return 0;
}

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Account {
private:
    static int count;            // Har account ka unique number banane ke liye counter.
    string accountNumber;        // Har account ki unique ID.
public:
    string accountHolder;        // Account holder ka naam.
    double balance;              // Account ka current balance.

    Account() {
        accountHolder = "Unknown";
        balance = 0.0;
        stringstream ss;
        ss << "AC" << setw(3) << setfill('0') << ++count;
        accountNumber = ss.str();
    }

    Account(string holder, double bal) : accountHolder(holder), balance(bal) {
        stringstream ss;
        ss << "AC" << setw(3) << setfill('0') << ++count;
        accountNumber = ss.str();
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into " << accountHolder << "'s account." << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from " << accountHolder << "'s account." << endl;
        } else {
            cout << "Insufficient funds in " << accountHolder << "'s account." << endl;
        }
    }

    // Operator + : 2 account ke balance ko add karne ke liye
    Account operator+(const Account &acc) {
        Account temp;
        temp.accountHolder = accountHolder + " & " + acc.accountHolder;
        temp.balance = balance + acc.balance;
        return temp;
    }

    // Operator -= : amount ko transfer karne ke liye
    Account &operator-=(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Transferred " << amount << " successfully from " << accountHolder << "'s account." << endl;
        } else {
            cout << "Transfer failed! Insufficient funds in " << accountHolder << "'s account." << endl;
        }
        return *this;
    }

    // Operator > : compares two account balances
    bool operator>(const Account &acc) {
        return balance > acc.balance;
    }

    // Friend function for stream insertion
    friend ostream &operator<<(ostream &out, const Account &acc);
};

// Static counter initialization
int Account::count = 0;

// Friend function definition
ostream &operator<<(ostream &out, const Account &acc) {
    out << "----------------------------------" << endl;
    out << "Account Number : " << acc.accountNumber << endl;
    out << "Account Holder : " << acc.accountHolder << endl;
    out << "Balance        : " << fixed << setprecision(2) << acc.balance << endl;
    out << "----------------------------------" << endl;
    return out;
}

int main() {
    // Creating two accounts
    Account acc1("Taqi", 5000);
    Account acc2("Shahid", 3000);

    cout << "Initial Account Details:" << endl;
    cout << acc1 << acc2;

    cout << "1. Adding Account 1 and Account 2 balances:" << endl;
    Account merged = acc1 + acc2;
    cout << merged;

    cout << "2. Transferring 2000 from Account 1 to Account 2:" << endl;
    acc1 -= 2000;
    acc2.deposit(2000);

    cout << endl << "After transfer:" << endl;
    cout << acc1 << acc2;

    cout << "3. Checking which account has a higher balance:" << endl;
    if (acc1 > acc2)
        cout << acc1.accountHolder << " has a higher balance." << endl;
    else
        cout << acc2.accountHolder << " has a higher balance." << endl;

    cout << endl << "4. Final account details:" << endl;
    cout << acc1 << acc2;

    return 0;
}

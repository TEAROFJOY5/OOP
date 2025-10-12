#include <iostream>
#include <string>
using namespace std;

class SecureBankAccount {
private:
    int accountNumber;
    double balance;
    const string accountType;
    int* logHistory;

public:
    SecureBankAccount(int accountNumber, double balance, string type, int logSize)
        : accountType(type) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        logHistory = new int(logSize);
        if (balance < 500.0) {
            cout << "Error: Initial balance must be at least 500.0 PKR" << endl;
        }
    }

    SecureBankAccount(const SecureBankAccount& other)
        : accountType(other.accountType) {
        this->accountNumber = other.accountNumber;
        this->balance = other.balance;
        logHistory = new int(*other.logHistory);
    }

    ~SecureBankAccount() {
        delete logHistory;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << " PKR" << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Log History Size: " << *logHistory << endl;
    }
};

int main() {
    SecureBankAccount a1(1001, 600.0, "Current", 5);
    cout << "Original Account:\n";
    a1.display();

    SecureBankAccount a2(a1);
    cout << "\nCopied Account:\n";
    a2.display();

    return 0;
}

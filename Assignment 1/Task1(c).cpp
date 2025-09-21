#include<iostream>
using namespace std;

class Loan {
    // Private attributes - encapsulation ka use
    string loanID;
    string borrowerName;
    double loanAmount;
    double interestRate;

public:
    // Constructor - naya loan record banane ke liye
    Loan(string id, string name, double amount, double rate) {
        loanID = id;
        borrowerName = name;
        loanAmount = amount;
        interestRate = rate;
    }

    // Copy Constructor - existing loan record ko duplicate karne ke liye
    Loan(const Loan &l) {
        loanID = l.loanID;
        borrowerName = l.borrowerName;
        loanAmount = l.loanAmount;
        interestRate = l.interestRate;
    }

    // Setters - data set karne ke liye
    void setLoanID(string id) { loanID = id; }
    void setBorrowerName(string name) { borrowerName = name; }
    void setLoanAmount(double amount) { loanAmount = amount; }
    void setInterestRate(double rate) { interestRate = rate; }

    // Getters - data read karne ke liye
    string getLoanID() { return loanID; }
    string getBorrowerName() { return borrowerName; }
    double getLoanAmount() { return loanAmount; }
    double getInterestRate() { return interestRate; }

    // Method to calculate total repayment (amount + interest)
    double calculateRepayment() {
        return loanAmount + (loanAmount * interestRate / 100);
    }

    // Loan details display karne ka method
    void display() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Borrower Name: " << borrowerName << endl;
        cout << "Loan Amount (PKR): " << loanAmount << endl;
        cout << "Interest Rate (%): " << interestRate << endl;
        cout << "Total Repayment (PKR): " << calculateRepayment() << endl;
    }
};

int main() {
    // Pehla loan record banaya
    Loan loan1("L001", " Turab Ali", 50000, 12.5);  // 12.5% interest on 50,000 PKR

    // Dusra loan, pehle wale ka copy
    Loan loan2 = loan1;

    // Display dono loan records
    cout << "--- Original Loan ---" << endl;
    loan1.display();

    cout << "\n--- Copied Loan ---" << endl;
    loan2.display();

    return 0;
}

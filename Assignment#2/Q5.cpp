#include <iostream>
#include <string>
using namespace std;

class Payment {
protected:
    string id;
    double amount;
public:
    Payment(string id, double amt) {
        this->id = id;
        this->amount = amt;
    }
    virtual double calcFee() const = 0;
    virtual string getType() const = 0;
    double getAmt() const {
        return amount;
    }
    string getID() const {
        return id;
    }
    virtual Payment* operator+(const Payment& p) const = 0;
    virtual void display() const {
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: " << amount << " PKR" << endl;
    }
    virtual ~Payment() {}
    friend void comparePayments(const Payment& a, const Payment& b);
};

class CreditCardPayment : public Payment {
public:
    CreditCardPayment(string id, double amt) : Payment(id, amt) {}
    double calcFee() const override {
        return amount * 0.02;
    }
    string getType() const override {
        return "CreditCard";
    }
    Payment* operator+(const Payment& p) const override {
        double total = amount + p.getAmt();
        double rate1 = 0.02, rate2;
        if (p.getType() == "CreditCard") rate2 = 0.02;
        else if (p.getType() == "Crypto") rate2 = 0.005;
        else rate2 = 20.0 / p.getAmt();
        double high = rate1 > rate2 ? rate1 : rate2;
        double fee = total * high;
        return new CreditCardPayment("Merge_TX", total - fee);
    }
};

class CryptoPayment : public Payment {
public:
    CryptoPayment(string id, double amt) : Payment(id, amt) {}
    double calcFee() const override {
        return amount * 0.005;
    }
    string getType() const override {
        return "Crypto";
    }
    Payment* operator+(const Payment& p) const override {
        double total = amount + p.getAmt();
        double rate1 = 0.005, rate2;
        if (p.getType() == "CreditCard") rate2 = 0.02;
        else if (p.getType() == "Crypto") rate2 = 0.005;
        else rate2 = 20.0 / p.getAmt();
        double high = rate1 > rate2 ? rate1 : rate2;
        double fee = total * high;
        return new CryptoPayment("Merge_TX", total - fee);
    }
};

class DigitalWalletPayment : public Payment {
public:
    DigitalWalletPayment(string id, double amt) : Payment(id, amt) {}
    double calcFee() const override {
        return 20.0;
    }
    string getType() const override {
        return "Wallet";
    }
    Payment* operator+(const Payment& p) const override {
        double total = amount + p.getAmt();
        double rate1 = 20.0 / amount, rate2;
        if (p.getType() == "CreditCard") rate2 = 0.02;
        else if (p.getType() == "Crypto") rate2 = 0.005;
        else rate2 = 20.0 / p.getAmt();
        double high = rate1 > rate2 ? rate1 : rate2;
        double fee = total * high;
        return new DigitalWalletPayment("Merge_TX", total - fee);
    }
};

void comparePayments(const Payment& a, const Payment& b) {
    if (a.amount > b.amount)
        cout << a.id << " has greater amount than " << b.id << endl;
    else if (a.amount < b.amount)
        cout << b.id << " has greater amount than " << a.id << endl;
    else
        cout << "Both payments are equal." << endl;
}

int main() {
    cout << "Turab Ali 24k-0651" << endl << endl;

    CreditCardPayment c1("TX01", 6000);
    CryptoPayment c2("TX02", 9000);
    DigitalWalletPayment c3("TX03", 2500);

    Payment* arr[] = { &c1, &c2, &c3 };

    for (int i = 0; i < 3; i++) {
        arr[i]->display();
        cout << "Type: " << arr[i]->getType() << endl;
        cout << "Fee: " << arr[i]->calcFee() << " PKR" << endl;
        cout << "Net: " << arr[i]->getAmt() - arr[i]->calcFee() << " PKR" << endl;
        cout << endl;
    }

    comparePayments(c1, c2);
    cout << endl;

    Payment* merge = *arr[0] + *arr[1];
    merge->display();
    cout << "Combined Transaction (higher fee applied)" << endl;
    cout << "Net Amount: " << merge->getAmt() << " PKR" << endl;

    delete merge;
    return 0;
}

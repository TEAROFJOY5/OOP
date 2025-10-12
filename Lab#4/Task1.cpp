#include <iostream>
#include <string>
using namespace std;

class MobileAccount {
private:
    double balance;
    string phoneNumber;

public:
    MobileAccount() {
        balance = 50.0;
        phoneNumber = "";
    }

    MobileAccount(string number, double initialBalance) {
        phoneNumber = number;
        balance = initialBalance;
    }

    void display() const {
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Balance: " << balance << " PKR" << endl;
    }
};

int main() {
    cout << "Default Account:\n";
    MobileAccount user1;
    user1.display();

    cout << "\nCustom Account:\n";
    MobileAccount user2("03001234567", 200.0);
    user2.display();

    return 0;
}

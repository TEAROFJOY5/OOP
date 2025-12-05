#include <iostream>
#include <limits>
using namespace std;

class CustomerBill {
public:
    double units;
    double costPerUnit;
    double bill;

    CustomerBill() {
        units = 0;
        costPerUnit = 15.0;
        bill = 0;
        cout << "Welcome to CityPower Services Billing System\n";
    }

    void calculateBill() {
        while (true) {
            try {
                cout << "Enter number of electricity units consumed: ";
                if (!(cin >> units)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw "Invalid input! Please enter numeric values only.";
                }

                if (units < 0) {
                    throw "Invalid input! Units cannot be negative.";
                }

                bill = units * costPerUnit;

                if (bill > 100000) {
                    throw "Bill exceeds limit! Please recheck the input.";
                }

                cout << "Total Bill: Rs " << bill << endl;
                break;

            } catch (const char* msg) {
                cout << "Error: " << msg << endl;
            }
        }
    }
};

int main() {
    CustomerBill customer;
    customer.calculateBill();
    cout << "Thank you for using CityPower Services.\n";
    return 0;
}

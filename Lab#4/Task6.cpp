#include <iostream>
#include <string>
using namespace std;

class OrderDetails {
private:
    int orderID;
    string itemName;
    const double deliveryFee;

public:
    OrderDetails(int orderID, string itemName, double deliveryFee)
        : deliveryFee(deliveryFee) {
        this->orderID = orderID;
        this->itemName = itemName;
    }

    ~OrderDetails() {
        cout << "Order " << orderID << " archived and memory cleared." << endl;
    }

    void display() const {
        cout << "Order ID: " << orderID << endl;
        cout << "Item: " << itemName << endl;
        cout << "Delivery Fee: " << deliveryFee << " PKR" << endl;
    }
};

int main() {
    OrderDetails order(1024, "Wireless Mouse", 250.0);
    order.display();
    return 0;
}

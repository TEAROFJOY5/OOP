#include <iostream>
using namespace std;
class Concrete {
private:
    string message;
public:
    Concrete(string msg) {
        message = msg;
    }
    void displayMessage() {
        cout << "Message: " << message << endl;
    }
};

int main() {
    Concrete c("Concrete Class Created.");
    c.displayMessage();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class CallRecord {
private:
    string ID;
    int durationMinutes;
    static int totalCalls;
public:
    CallRecord(string id = "", int d = 0) {
        ID = id;
        durationMinutes = d;
        totalCalls++;  
    }

    void display() const {
        cout << "Caller ID: " << ID << ", Duration: " << durationMinutes << " minutes" << endl;
    }

    static int getTotalCalls() {
        return totalCalls;
    }
};


int CallRecord::totalCalls = 0;

int main() {
   
    CallRecord shiftCalls[20] = {
        {"03001256567", 5}, {"03019376543", 3}, {"031869235467", 10},
        {"03211278567", 4}, {"033344234567", 6}, {"03451263567", 7},
        {"03321224567", 2}, {"03171234567", 8}, {"03281234567", 9},
        {"03341239567", 1}, {"03461234567", 3}, {"03031267567", 6},
        {"03141224567", 4}, {"03223124567", 7}, {"03387234567", 2},
        {"03451934567", 10}, {"03041234567", 3}, {"03157634567", 5},
        {"03241230567", 6}, {"03361254567", 8}
    };

  
    for (int i = 0; i < 20; ++i) {
        shiftCalls[i].display();
    }

    cout << "\nTotal calls logged: " << CallRecord::getTotalCalls() << endl;

    return 0;
}

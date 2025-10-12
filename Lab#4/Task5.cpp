#include <iostream>
using namespace std;

class ServerSession {
private:
    int sessionID;

public:
    ServerSession(int id) {
        sessionID = id;
        cout << "Session " << sessionID << " started. Resource acquired." << endl;
    }

    ~ServerSession() {
        cout << "Session " << sessionID << " ended. Resource released." << endl;
    }
};

int main() {
    cout << "Entering session block...\n";

    {
        ServerSession s1(101);  
    } 

    cout << "Exited session block.\n";

    return 0;
}

#include <iostream>
using namespace std;

class TitleRecord {
private:
    int* ownersCode;

public:
    TitleRecord(int code) {
        ownersCode = new int(code);
        cout << "Init: " << ownersCode << " holds " << *ownersCode << endl;
    }

    TitleRecord(const TitleRecord& ref, bool isShallow) {
        if (isShallow) {
            ownersCode = ref.ownersCode;
            cout << "Shallow Copy: " << ownersCode << endl;
        }
    }

    TitleRecord(const TitleRecord& ref) {
        ownersCode = new int(*ref.ownersCode);
        cout << "Deep Copy: " << ownersCode << " holds " << *ownersCode << endl;
    }

    void updateCode(int code) {
        *ownersCode = code;
    }

    void show() const {
        cout << "Owner's Code: " << *ownersCode << " at " << ownersCode << endl;
    }

    ~TitleRecord() {
        cout << "Freeing: " << ownersCode << endl;
        delete ownersCode;
    }
};

int main() {
    cout << "\nOriginal Record\n";
    TitleRecord a(5005);

    cout << "\nShallow Clone\n";
    TitleRecord b(a, true);

    cout << "\nDeep Clone\n";
    TitleRecord c(a);

    cout << "\nBefore Update:\n";
    cout << "A: "; a.show();
    cout << "B: "; b.show();
    cout << "C: "; c.show();

    cout << "\nUpdating A's Code to 9999\n";
    a.updateCode(9999);

    cout << "\nAfter Update:\n";
    cout << "A: "; a.show();
    cout << "B: "; b.show();
    cout << "C: "; c.show();

    cout << "\nDone.\n";
    return 0;
}

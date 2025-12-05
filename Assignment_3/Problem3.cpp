#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <type_traits>
using namespace std;

struct PacketHeader {
    char magic[4];        
    int version;         
    int typeSize;         
    int count;            // Kitne elements store ho rahe hain
    int trivFlag;         // 1 = trivially copyable (safe), 0 = unsafe
};

class PacketIDGen {
private:
    static int counter;

public:
    static string getNextID() {
        stringstream ss;
        ss << "P" << setw(4) << setfill('0') << ++counter;
        return ss.str();
    }
};

int PacketIDGen::counter = 0;


template <typename T, int N>
class DataPacket {

    static_assert(std::is_trivially_copyable<T>::value,
        "ERROR: DataPacket<T,N> can only be used with trivially copyable types (no pointers, no strings).");

private:
    T data[N];            
    
    string packetID;     

public:

    DataPacket() {
        packetID = PacketIDGen::getNextID();
        // Initialize array with zero
        for (int i = 0; i < N; i++) data[i] = T();
        cout << "\nPacket Created | ID = " << packetID << endl;
    }

    void setValue(int index, T val) {
        if (index >= 0 && index < N)
            data[index] = val;
    }

    string getID() const {
        return packetID;
    }

    bool writeToBinary(string filename) {
        ofstream fout(filename, ios::binary | ios::app);
        if (!fout) return false;

        // Create header
        PacketHeader hdr;
        hdr.magic[0] = 'D'; hdr.magic[1] = 'P';
        hdr.magic[2] = 'K'; hdr.magic[3] = 'T';
        hdr.version = 1;
        hdr.typeSize = sizeof(T);
        hdr.count = N;
        hdr.trivFlag = 1;

        // Write header
        fout.write(reinterpret_cast<char*>(&hdr), sizeof(hdr));

        // Write entire fixed-size array
        fout.write(reinterpret_cast<char*>(data), sizeof(T) * N);

        fout.close();
        return true;
    }
    static bool readFromBinary(ifstream& fin, DataPacket<T, N>& outPacket) {
        if (!fin) return false;

        PacketHeader hdr;

        // Read header
        fin.read(reinterpret_cast<char*>(&hdr), sizeof(hdr));
        if (!fin) return false;

        // Validate header
        if (hdr.magic[0] != 'D' || hdr.magic[1] != 'P' ||
            hdr.magic[2] != 'K' || hdr.magic[3] != 'T') {
            cout << "Invalid header magic. Skipping.\n";
            return false;
        }

        if (hdr.typeSize != sizeof(T)) {
            cout << "TypeSize mismatch. File has different type.\n";
            return false;
        }

        if (hdr.count != N) {
            cout << "Count mismatch. Expected " << N << " but file has " << hdr.count << endl;
            return false;
        }

        if (hdr.trivFlag != 1) {
            cout << "Unsafe packet detected (contains non-trivial type).\n";
            return false;
        }

        // Read the fixed-size array
        fin.read(reinterpret_cast<char*>(outPacket.data), sizeof(T) * N);
        if (!fin) return false;

        return true;
    }

    void show() const {
        cout << "Packet " << packetID << " Data: ";
        for (int i = 0; i < N; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    cout << "\nSAFE TEMPLATE + BINARY FILE HANDLING (NO VECTORS)\n";

    DataPacket<double, 5> tempPkt;
    tempPkt.setValue(0, 36.5);
    tempPkt.setValue(1, 36.7);
    tempPkt.setValue(2, 36.4);
    tempPkt.setValue(3, 36.6);
    tempPkt.setValue(4, 36.5);

    tempPkt.writeToBinary("health.bin");

    DataPacket<int, 5> batteryPkt;
    batteryPkt.setValue(0, 100);
    batteryPkt.setValue(1, 98);
    batteryPkt.setValue(2, 95);
    batteryPkt.setValue(3, 92);
    batteryPkt.setValue(4, 90);

    batteryPkt.writeToBinary("health.bin");

    ifstream fin("health.bin", ios::binary);

    cout << "\nReading packets from file...\n";

    // Read first as double-packet
    DataPacket<double, 5> readTemp;
    if (DataPacket<double, 5>::readFromBinary(fin, readTemp)) {
        readTemp.show();
    }

    // Read second as int-packet
    DataPacket<int, 5> readBat;
    if (DataPacket<int, 5>::readFromBinary(fin, readBat)) {
        readBat.show();
    }

    fin.close();

    cout << "\n--- DONE ---\n";

    return 0;
}

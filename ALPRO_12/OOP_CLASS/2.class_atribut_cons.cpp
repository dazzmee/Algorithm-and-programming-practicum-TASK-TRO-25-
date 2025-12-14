#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;

public:
    // Constructor
    Mahasiswa(string nm, int um) {
        nama = nm;
        umur = um;
    }

    void tampilkan() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }
};

int main() {
    Mahasiswa m("Izzad", 18);
    m.tampilkan();
    return 0;
}

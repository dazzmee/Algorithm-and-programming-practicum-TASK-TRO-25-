#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
public:
    string nama;
    int umur;

    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }
};

int main() {
    Mahasiswa m;
    m.nama = "Izzad";
    m.umur = 18;

    m.tampilkanInfo();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Manusia {
protected:
    string nama;

public:
    Manusia(string nm) {
        nama = nm;
    }

    void sapa() {
        cout << "Halo, saya " << nama << endl;
    }
};

class Mahasiswa : public Manusia {
private:
    string jurusan;

public:
    Mahasiswa(string nm, string jr) : Manusia(nm) {
        jurusan = jr;
    }

    void tampilkanData() {
        cout << "Nama: " << nama << endl;
        cout << "Jurusan: " << jurusan << endl;
    }
};

int main() {
    Mahasiswa m("Izzad", "Teknologi rekayasa otomasi");

    m.sapa();
    m.tampilkanData();

    return 0;
}

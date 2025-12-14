//menambahkan method setUmur dan getUmur.

#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;

public:
    Mahasiswa(string nm, int um) {
        nama = nm;
        umur = um;
    }

    void tampilkan() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }

    void setUmur(int baru) {
        umur = baru;
    }

    int getUmur() {
        return umur;
    }
};

int main() {
    Mahasiswa m("Izzad", 18);
    m.tampilkan();

    m.setUmur(22);
    cout << "Umur baru: " << m.getUmur() << endl;

    return 0;
}

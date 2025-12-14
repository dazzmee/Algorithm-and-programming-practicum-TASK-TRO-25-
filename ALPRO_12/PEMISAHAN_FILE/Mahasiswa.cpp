#include "Mahasiswa.hpp"
#include <iostream>
using namespace std;

Mahasiswa::Mahasiswa(string nm, int um) {
    nama = nm;
    umur = um;
}

void Mahasiswa::tampilkan() {
    cout << "Nama: " << nama << endl;
    cout << "Umur: " << umur << endl;
}

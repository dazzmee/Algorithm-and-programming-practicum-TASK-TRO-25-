#include "Mahasiswa.hpp"
#include <iostream>
using namespace std;

Mahasiswa::Mahasiswa(string nm, string jr) : Manusia(nm) {
    jurusan = jr;
}

void Mahasiswa::tampilkanData() {
    cout << "Nama: " << nama << endl;
    cout << "Jurusan: " << jurusan << endl;
}

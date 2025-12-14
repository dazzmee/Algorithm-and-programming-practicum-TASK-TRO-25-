#ifndef MAHASISWA_HPP
#define MAHASISWA_HPP

#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;

public:
    Mahasiswa(string nm, int um);
    void tampilkan();
};

#endif

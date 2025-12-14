#ifndef MAHASISWA_HPP
#define MAHASISWA_HPP

#include "Manusia.hpp"
using namespace std;

class Mahasiswa : public Manusia {
private:
    string jurusan;

public:
    Mahasiswa(string nm, string jr);
    void tampilkanData();
};

#endif

#include "Mahasiswa.hpp"

int main() {
    Mahasiswa m("Izzad", "Teknologi rekayasa otomasi");

    m.sapa();
    m.tampilkanData();

    return 0;
}

// g++ main.cpp Manusia.cpp Mahasiswa.cpp -o program
// ./program
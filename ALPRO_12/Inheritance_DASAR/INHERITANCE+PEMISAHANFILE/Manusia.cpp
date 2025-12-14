#include "Manusia.hpp"
#include <iostream>
using namespace std;

Manusia::Manusia(string nm) {
    nama = nm;
}

void Manusia::sapa() {
    cout << "Halo, saya " << nama << endl;
}

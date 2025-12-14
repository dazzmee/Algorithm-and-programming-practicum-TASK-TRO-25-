#include <iostream>

using namespace std;



int nilaiGlobal = 10; // variabel global

void cetak() {
    int nilaiLokal = 5; // variabel lokal
    cout << "Nilai global: " << nilaiGlobal << endl;
    cout << "Nilai lokal: " << nilaiLokal << endl;
}

int main() {
    cetak();
    cout << "Akses variabel global di main: " << nilaiGlobal << endl;

    return 0;
}

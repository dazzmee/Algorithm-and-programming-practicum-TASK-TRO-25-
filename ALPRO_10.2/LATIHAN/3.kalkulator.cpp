#include <iostream>
using namespace std;

int main() {
    int pilihan;
    float a, b;

    cout << "=== KALKULATOR MINI ===\n";
    cout << "1. Tambah\n2. Kurang\n3. Kali\n4. Bagi\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;

    switch (pilihan) {
        case 1: cout << "Hasil = " << (a + b); break;
        case 2: cout << "Hasil = " << (a - b); break;
        case 3: cout << "Hasil = " << (a * b); break;
        case 4: cout << "Hasil = " << (a / b); break;
        default: cout << "Menu tidak valid!"; break;
    }

    cout << endl;
    return 0;
}

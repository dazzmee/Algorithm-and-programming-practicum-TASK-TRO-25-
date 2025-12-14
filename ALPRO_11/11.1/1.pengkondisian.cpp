#include <iostream>
using namespace std;

int main() {
    int umur;

    cout << "Masukkan umur kamu: ";
    cin >> umur;

    if (umur < 13) {
        cout << "Kamu masih anak-anak.\n";
    }
    else if (umur >= 13 && umur <= 18) {
        cout << "Kamu remaja.\n";
    }
    else if (umur >= 18 && umur <= 60) {
        cout << "Kamu dewasa.\n";
    }
    else {
        cout << "Kamu sudah lanjut usia.\n";
    }

    return 0;
}

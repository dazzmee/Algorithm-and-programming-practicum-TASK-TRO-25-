#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> daftar;
    string nama;
    int jumlah;

    cout << "Berapa banyak nama yang ingin dimasukkan? ";
    cin >> jumlah;
    cin.ignore(); // membersihkan newline

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama ke-" << (i+1) << ": ";
        getline(cin, nama);
        daftar.push_back(nama);
    }

    cout << "\nDaftar nama yang dimasukkan:\n";
    for (string n : daftar) {
        cout << "- " << n << endl;
    }
    return 0;
}

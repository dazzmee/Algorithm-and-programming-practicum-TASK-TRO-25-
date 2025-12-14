#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> namaBarang;
    vector<int> hargaBarang;

    int pilihan;

    while (true) {
        cout << "\n=== MENU KASIR SEDERHANA ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Hitung Total Belanja\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            int harga;

            cout << "Masukkan nama barang: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Masukkan harga barang: ";
            cin >> harga;

            namaBarang.push_back(nama);
            hargaBarang.push_back(harga);

            cout << "Barang ditambahkan!\n";
        }
        else if (pilihan == 2) {
            cout << "\n=== DAFTAR BARANG ===\n";
            if (namaBarang.empty()) {
                cout << "Belum ada barang!\n";
            } else {
                for (int i = 0; i < namaBarang.size(); i++) {
                    cout << i+1 << ". " << namaBarang[i]
                         << " - Rp " << hargaBarang[i] << endl;
                }
            }
        }
        else if (pilihan == 3) {
            int total = 0;

            for (int i = 0; i < hargaBarang.size(); i++) {
                total += hargaBarang[i];
            }

            cout << "\nTotal belanja: Rp " << total << endl;
        }
        else if (pilihan == 4) {
            cout << "Keluar...\n";
            break;
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

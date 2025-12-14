#include <iostream>
#include <cstdlib>  // untuk rand()
#include <ctime>    // untuk time()
using namespace std;

int main() {
    srand(time(0));          // seed random
    int angkaRahasia = rand() % 10 + 1; // angka 1–10
    int tebakan;

    cout << "=== GAME TEBAK ANGKA ===\n";
    cout << "Aku sudah memilih angka dari 1 sampai 10.\n";
    cout << "Coba tebak!\n\n";

    while (true) {
        cout << "Masukkan tebakanmu: ";
        cin >> tebakan;

        if (tebakan == angkaRahasia) {
            cout << "🎉 Keren! Kamu berhasil menebaknya!\n";
            break;
        }
        else if (tebakan > angkaRahasia) {
            cout << "Terlalu besar! Coba angka yang lebih kecil.\n";
        }
        else {
            cout << "Terlalu kecil! Coba angka yang lebih besar.\n";
        }
    }

    cout << "\nTerima kasih sudah bermain!\n";
    return 0;
}

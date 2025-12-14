#include <iostream>
using namespace std;

#define PI 3.14159   // konstanta menggunakan #define
#define LUAS_LINGKARAN(r) (PI * (r) * (r))  // macro untuk menghitung luas lingkaran


int main() {
    float r;

    cout << "Masukkan jari-jari: ";
    cin >> r;

    float keliling = 2 * PI * r;
    float luas = LUAS_LINGKARAN(r);

    cout << "Keliling lingkaran = " << keliling << endl;
    cout << "Luas lingkaran = " << luas << endl;
    return 0;
}

#include <iostream>
using namespace std;

void tambahSatu(int &x) {
    x = x + 1;
}

int main() {
    int nilai;
    cout << "Masukkan sebuah nilai: ";
    cin >> nilai;
    tambahSatu(nilai);

    cout << "Nilai di main (berubah): " << nilai << endl;
    return 0;
}

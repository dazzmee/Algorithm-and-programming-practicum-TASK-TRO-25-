#include <iostream>
using namespace std;

void tambahSatu(int x) {
    x = x + 1;
    cout << "Nilai di dalam fungsi: " << x << endl;
}

int main() {
    int nilai;
    cout << "Masukkan sebuah nilai: ";
    cin >> nilai;
    tambahSatu(nilai);

    cout << "Nilai di main (tidak berubah): " << nilai << endl;
    return 0;
}



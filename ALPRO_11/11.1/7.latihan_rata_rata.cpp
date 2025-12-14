#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Berapa banyak nilai yang akan dimasukkan? ";
    cin >> n;

    int total = 0;
    int nilai;

    for (int i = 1; i <= n; i++) {
        cout << "Masukkan nilai ke-" << i << ": ";
        cin >> nilai;
        total += nilai;
    }

    cout << "Rata-rata = " << (float)total / n << endl;
    return 0;
}

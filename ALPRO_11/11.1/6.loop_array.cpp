#include <iostream>
using namespace std;

int main() {
    int nilai[5] = {80, 75, 90, 60, 88};

    cout << "Daftar nilai:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i+1 << ": " << nilai[i] << endl;
    }

    return 0;
}

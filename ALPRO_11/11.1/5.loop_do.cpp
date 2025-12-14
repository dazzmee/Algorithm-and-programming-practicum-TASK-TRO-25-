#include <iostream>
using namespace std;

int main() {
    int input;

    do {
        cout << "Masukkan angka 0 untuk berhenti: ";
        cin >> input;
    } while (input != 0);

    cout << "Program selesai.\n";
    return 0;
}

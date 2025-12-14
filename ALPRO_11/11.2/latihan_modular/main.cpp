#include <iostream>
#include "menu.hpp"
using namespace std;

int main() {
    int pilihan;

    tampilMenu();
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "Halo! Senang bertemu.\n";
    } else {
        cout << "Bye!\n";
    }

    return 0;
}


// g++ main.cpp menu.cpp -o program
// ./program

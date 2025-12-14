#include <iostream>
using namespace std;

void sapa(); // deklarasi (prototype)

int main() {
    sapa(); // pemanggilan
    return 0;
}

void sapa() { // definisi
    cout << "Halo dari fungsi terpisah!\n";
}

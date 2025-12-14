// #include <iostream>
// using namespace std;

// void halo() {
//     cout << "Halo! Ini fungsi tanpa parameter." << endl;
// }

// void nama(){
//     cout << "Izzad" << endl;
// }

// int main() {
//     halo();
//     nama();
//     return 0;
// }


//dengan parameter
// #include <iostream>
// using namespace std;

// void sapa(string nama) {
//     cout << "Halo " << nama << "!" << endl;
// }

// int main() {
//     sapa("Desta");
//     sapa("Izzad");
//     return 0;
// }



//dengan return value
#include <iostream>
using namespace std;

int tambah(int a, int b) {
    return a + b;
}
int perkalian(int a, int b) {
    return a * b;
}

int main() {
    int hasil = tambah(5, 3);
    cout << "Hasil penjumlahan: " << hasil << endl;
    cout << "Hasil perkalian: " << perkalian(4, 6) << endl;
    return 0;
}




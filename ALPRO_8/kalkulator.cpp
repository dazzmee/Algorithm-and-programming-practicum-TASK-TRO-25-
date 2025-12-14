#include <iostream>
using namespace std;
int main(){

    cout << "=========KALKULATOR SEDERHANA=========" << endl;
    float a,b;
    int pilihan;
    cout << "masukkan nilai a : ";
    cin >> a;
    cout << "masukkan nilai b : ";
    cin >> b;

    cout << "Pilih operasi yang diinginkan : " << endl;
    cout << "1. Penjumlahan (+)" << endl;
    cout << "2. Pengurangan (-)" << endl;
    cout << "3. Perkalian (*)" << endl;
    cout << "4. Pembagian (/)" << endl;
    cout << "Masukkan pilihan (1/2/3/4) : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        cout << "Hasil penjumlahan : " << a+b << endl;
        break;
    case 2:
        cout << "Hasil pengurangan : " << a-b << endl;
        break;
    case 3:
        cout << "Hasil perkalian : " << a*b << endl;
        break;
    case 4:
        if(b = 0){
            cout << "Error : tidak bisa melakukan pembagian dengan nol" << endl;
        } else {
            cout << "Hasil pembagian : " << a/b << endl;
        }
    default:
        break;
    }

}
#include <iostream>
using namespace std;
int main(){
    string nama;
    cout << "Masukkan nama anda : ";
    cin >> nama;
    cout << "Halo, nama saya " << nama << ", saya adalah mahasiswa di Universitas diponegoro" << endl;

    int umur = 18;
    cout << umur << endl;

    float ipk = 3.99;
    double phi = 3.14159;

    cout << sizeof(umur) << endl;
    cout << sizeof(phi) << endl;

    long long int populasi = 10000000000000;
    cout << populasi << endl;

}
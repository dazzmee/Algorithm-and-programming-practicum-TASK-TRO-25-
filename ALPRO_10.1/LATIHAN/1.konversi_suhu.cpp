#include <iostream>
using namespace std;

int main() {
    float celsius;
    cout << "Masukkan suhu Celsius: ";
    cin >> celsius;

    float fahrenheit = (celsius * 9/5) + 32;

    cout << "Hasil: " << fahrenheit << " °F" << endl;
    return 0;
}

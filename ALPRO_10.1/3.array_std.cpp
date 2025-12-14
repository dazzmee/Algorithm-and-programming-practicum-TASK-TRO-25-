// #include <iostream>
// using namespace std;

// int main() {
//     int nilai[5] = {90, 85, 75, 88, 92};

//     cout << "Daftar nilai:" << endl;
//     for (int i = 0; i < 5; i++) {
//         cout << nilai[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> nama;

    nama.push_back("Andi");
    nama.push_back("Budi");
    nama.push_back("Cici");

    cout << "Daftar nama:" << endl;
    for (string n : nama) {
        cout << "- " << n << endl;
    }
    return 0;
}

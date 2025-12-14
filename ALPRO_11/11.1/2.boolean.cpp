#include <iostream>
using namespace std;

int main() {
    bool a = true;
    bool b = false;

    cout << "a && b = " << (a && b) << endl; // false
    cout << "a || b = " << (a || b) << endl; // true
    cout << "!a = " << (!a) << endl;         // false

    return 0;
}

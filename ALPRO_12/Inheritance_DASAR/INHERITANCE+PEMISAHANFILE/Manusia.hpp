#ifndef MANUSIA_HPP
#define MANUSIA_HPP

#include <string>
using namespace std;

class Manusia {
protected:
    string nama;

public:
    Manusia(string nm);
    void sapa();
};

#endif

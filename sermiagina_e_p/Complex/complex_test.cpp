//
// Created by Елена Сермягина on 21.09.17.
//
#include "complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success:" << str << " -> " << z << endl;
    } else {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();


}

int main()
{
    using namespace std;

    Complex z;
    cout << "Initial complex number: " << z;
    z += Complex(8.0);
    cout << "8.0 added: " << z;
    z -= Complex(3.0, -4);

    cout << z;
    z -= 6.0;
    cout << z;
    z *= 6.0;
    cout << z;
     //testParse("{8.9,9}");
    // testParse("{8.9, 9}");
    // testParse("{8.9,9");

    //сделать понятно

    return 0;
}


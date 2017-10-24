//
// Created by Елена Сермягина on 19.10.2017.
//

#include <iostream>
#include <sstream>
#include "kvaternion.h"

using namespace std;

void mathTest(Kvaternion kva, Kvaternion kvakva)
{
    cout << endl <<"First: " << kva << endl;
    cout << "Second: " << kvakva << endl << endl;

    cout << "Math test:" << endl << endl;

    cout << kva << " + " << kvakva << " = "<< (kva + kvakva) << endl;
    cout << kva << " - " << kvakva << " = "<< (kva - kvakva) << endl;
    cout << kva << " * " << 2.0 << " = "<< (kva * 2.0) << endl;
    cout << 3.0 << " * " << kvakva << " = "<< (3.0 * kvakva) << endl << endl;

    cout << "first = " << kva << "; first += {7.0, 2.0, 5.0, 3.0}; first = ";
    kva += Kvaternion{7.0, 2.0, 5.0, 3.0};
    cout << kva << endl;

    cout << "first = " << kva << "; first -= {9.0, 1.0, -5.0, 3.0}; first = ";
    kva -= Kvaternion{9.0, 1.0, -5.0, 3.0};
    cout << kva << endl;

    cout << "first = " << kva << "; first *= {2.0, 1.0, -2.0, 3.0}; first = ";
    kva *= Kvaternion{2.0, 1.0, -2.0, 3.0};
    cout << kva << endl;

    cout << endl << "Length of:" << kva << " = "<< kva.Magnitude() << endl;
    cout << "Determintor of:" << kva << " = "<< kva.Determinator() << endl;
    cout << "Scalar product :" << kva << " * " << kvakva << " = "<< kva.innerProduct(kvakva) << endl;



    cout << "______________________________________________________"  << endl;






};


int main() {

    std::cout << endl << "Constructors:" << std::endl << endl;
    Kvaternion cv(2.0, 3.0, 4.0, 5.0);
    Kvaternion c;
    Kvaternion cva(cv);
    std::cout <<"Default: " << c << std::endl;
    std::cout <<"With 4 values: " <<cv << std::endl;
    std::cout <<"Copy: " <<cva << std::endl;
    cout << "______________________________________________________"  << endl;

    mathTest({2.0, 3.0, 4.0, 6.0},{-2.0, 0.0, -4.0, 2.2});

    return 0;
}

//
// Created by Елена Сермягина on 21.09.17.
//
#include "complex.h"
#include <iostream>
#include <sstream>

using namespace std;

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

void mathTest(Complex first, Complex second) {

    cout << endl << "Math tests:"<< endl;

    Complex one(first);
    Complex two(second);

    cout << one << " is equal to " << two << " ? " << (one == two) << endl;
    cout << one << " isn't equal to " << two << " ? " << (one != two) << endl << endl;

    cout << "Complex and Complex:" << endl;
    cout << one << " + " << two << " = " << (one + two) << endl;
    cout << one << " - " << two << " = " << (one - two) << endl;
    cout << one << " * " << two << " = " << (one * two) << endl;
    cout << one << " / " << two << " = " << (one / two) << endl << endl;

    cout << "Complex and Double:" << endl;
    cout << one << " + " << 7.0 << " = " << (one + 7.0) << endl;
    cout << one << " - " << 7.0 << " = " << (one - 7.0) << endl;
    cout << one << " * " << 7.0 << " = " << (one * 7.0) << endl;
    cout << one << " / " << 7.0 << " = " << (one / 7.0) << endl << endl;

    cout << "one = " << one << "; one += {8, 2}; one = ";
    one += Complex{8, 2};
    cout << one << endl;

    cout << "one = " << one << "; one -= {4, 2}; one = ";
    one -= Complex{4, 2};
    cout << one << endl;

    cout << "one = " << one << "; one *= {2, 2}; one = ";
    one -= Complex{2, 2};
    cout << one << endl;

    cout << "one = " << one << "; one /= {1, 2}; one = ";
    one -= Complex{1, 2};
    cout << one << endl;


    cout << "one = " << one << "; one += 5.0; one = ";
    one += 5.0;
    cout << one << endl;

    cout << "one = " << one << "; one -= 2.0; one = ";
    one -= 2.0;
    cout << one << endl;

    cout << "one = " << one << "; one *= 3.0; one = ";
    one *= 3.0;
    cout << one << endl;

    cout << "one = " << one << "; one /= 3.0; one = ";
    one /= 1.2;
    cout << one << endl;


};

void parseTest(){

    cout << "Parse test: " << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
}

int main()
{
    mathTest({2,1}, {3,0});
    cout<<endl;
    parseTest();

    return 0;
}


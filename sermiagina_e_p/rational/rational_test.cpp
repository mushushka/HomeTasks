//
// Created by Елена Сермягина on 21.09.17.
//
#include "rational.h"
#include <iostream>
#include <sstream>

using namespace std;

void equalityTest(Rational first, Rational second)
{
    Rational one(first);
    Rational two(second);

    cout << endl << "First rational: " << one << endl;
    cout << "Second rational: " << two << endl;

    cout << endl << "Equality test: " << endl;

    cout << one << " is greater than " << two << " ? " << (one > two) << endl;
    cout << one << " is less than " << two << " ? " << (one < two) << endl;
    cout << one << " is greater than or equal to " << two << " ? " << (one >= two) << endl;
    cout << one << " is less than or equal to " << two << " ? " << (one <= two) << endl;
    cout << one << " is equal to " << two << " ? " << (one == two) << endl;
    cout << one << " isn't equal to " << two << " ? " << (one != two) << endl << endl;

    cout << endl << "Vice versa: " << endl;

    cout << two << " is greater than " << one << " ? " << (one < two) << endl;
    cout << two << " is less than " << one << " ? " << (one > two) << endl;
    cout << two << " is greater than or equal to " << one << " ? " << (one <= two) << endl;
    cout << two << " is less than or equal to " << one << " ? " << (one >= two) << endl;
    cout << two << " is equal to " << one << " ? " << (one == two) << endl;
    cout << two << " isn't equal to " << one << " ? " << (one != two) << endl << endl;


}

void mathTest(Rational first, Rational second) {

    cout << endl << "Math tests:"<< endl << endl;

    Rational one(first);
    Rational two(second);

    cout << endl << "First rational: " << one << endl;
    cout << "Second rational: " << two << endl;

    cout << "Plus to minus or minus to plus:" << endl << endl;
    cout << "one = " << one << "; -one = ";
    cout << -one << endl;
    cout << "two = " << two << "; -two = ";
    cout << -two << endl;




    cout << "Rational and Rational:" << endl << endl;
    cout << one << " + " << two << " = " << (one + two) << endl;
    cout << one << " - " << two << " = " << (one - two) << endl;
    cout << one << " * " << two << " = " << (one * two) << endl;
    cout << one << " / " << two << " = " << (one / two) << endl << endl;

    cout << "Rational and Integer:" << endl;
    cout << one << " + " << 7 << " = " << (one + 7) << endl;
    cout << one << " - " << 7 << " = " << (one - 7) << endl;
    cout << one << " * " << 7 << " = " << (one * 7) << endl;
    cout << one << " / " << 7 << " = " << (one / 7) << endl << endl;

    cout << "Integer and Rational:" << endl;
    cout << 7 << " + " << one << " = " << (one + 7) << endl;
    cout << 7 << " - " << one << " = " << (one - 7) << endl;
    cout << 7 << " * " << one << " = " << (one * 7) << endl;
    cout << 7 << " / " << one << " = " << (one / 7) << endl << endl;




    cout << "one = " << one << "; one += 7/2; one = ";
    one += Rational{7, 2};
    cout << one << endl;

    cout << "one = " << one << "; one -= 4/2; one = ";
    one -= Rational{4, 2};
    cout << one << endl;

    cout << "one = " << one << "; one *= 2/2; one = ";
    one *= Rational{2, 2};
    cout << one << endl;

    cout << "one = " << one << "; one /= 5/8; one = ";
    one /= Rational{5, 8};
    cout << one << endl;


    cout << "one = " << one << "; one += 5; one = ";
    one += 5;
    cout << one << endl;

    cout << "one = " << one << "; one -= 2; one = ";
    one -= 2;
    cout << one << endl;

    cout << "one = " << one << "; one *= 3; one = ";
    one *= 3;
    cout << one << endl;

    cout << "one = " << one << "; one /= 4; one = ";
    one /= 4;
    cout << one << endl;


}

//add constructors' test

int main() {

    equalityTest({7,3},{1,4});
    equalityTest({1,22223},{1,33334});
    mathTest({3,1}, {5,8});
    mathTest({-2,-1}, {-3,3});

    cout<<endl;





    return 0;
}

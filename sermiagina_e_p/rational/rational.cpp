//
// Created by Елена Сермягина on 21.09.17.
//
#include "rational.h"
#include <iostream>


using namespace std;

Rational::Rational(const int complete): _complete(complete){}

Rational::Rational(const int complete, const int natural)
        : _complete(complete),
          _natural(natural)
{
    if (_natural == 0) {

        throw invalid_argument("Zero in natural");
    }
    normalize();
    commonDivivsor(_complete, _natural);
}


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << _complete << "/" << _natural;
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, Rational number)
{
    return number.writeTo(ostr);
}


int Rational::commonDivivsor(int firstNumber, int secondNumber) {

    while (firstNumber && secondNumber) {
        if (abs(firstNumber) > abs(secondNumber)) {
            firstNumber = abs(firstNumber % secondNumber);
        } else {
            secondNumber = abs(secondNumber % firstNumber);
        }

    }
    return (firstNumber + secondNumber);
}



Rational& Rational::operator/=(const Rational &number) {

    _complete *= number._natural;
    _natural *= number._complete;
    normalize();

    return *this;
}


Rational& Rational::operator*=(const Rational &number) {
    _complete *= number._complete;
    _natural *= number._natural;
    normalize();

    return *this;
}

Rational& Rational::operator+=(const Rational &number) {
    _complete = _complete*number._natural + number._complete*_natural;
    _natural*=number._natural;
    normalize();

    return *this;

}

Rational& Rational::operator-=(const Rational &number) {
    _complete = _complete*number._natural - number._complete*_natural;
    _natural*=number._natural;
    normalize();


    return *this;
}


void Rational::normalize() {
    int nod = commonDivivsor(_complete, _natural);
    _complete/=nod;
    _natural/=nod;
}



bool Rational::isPositive() {
    return (_natural > 0) && (_complete > 0);
}


// binary operators

Rational operator+(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result+= secondNumber;

    return result;
}

Rational operator-(const Rational& firstNumber, const Rational& secondNumber){
    Rational result = firstNumber;
    result -= secondNumber;

    return result;
}

Rational operator*(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result *= secondNumber;

    return result;
}

Rational operator/(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result /= secondNumber;

    return result;
}

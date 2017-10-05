//
// Created by Елена Сермягина on 21.09.17.
//
#include "rational.h"
#include <iostream>
#include <sstream>
#include <cmath>


using namespace std;

Rational::Rational(const int complete): _complete(complete), _natural(1){}

Rational::Rational(const int complete, const int natural)
        : _complete(complete),
          _natural(natural)
{
    if (_natural == 0)
    {
       // throw invalid_argument("Zero in natural");
    }
    normalize();
    //commonDivivsor(_complete, _natural);
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


int Rational::commonDivivsor(int firstNumber, int secondNumber)
{

    while (firstNumber && secondNumber) {
        if (abs(firstNumber) > abs(secondNumber))
        {
            firstNumber = abs(firstNumber % secondNumber);
        } else {
            secondNumber = abs(secondNumber % firstNumber);
        }

    }
    return (firstNumber + secondNumber);
}

//int Rational::leastCommonMultiple(int firstNUmber, int secondNumber)
//{
//    int lcm =  (firstNUmber*secondNumber)/commonDivivsor(firstNUmber,secondNumber);

 //   return lcm;
//}


//division
Rational& Rational::operator/=(const Rational &number)
{

    _complete *= number._natural;
    _natural *= number._complete;
    normalize();

    return *this;
}

Rational& Rational::operator/=(const int number)
{
    return operator/=(Rational(number));
}

Rational operator/(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational result = firstNumber;
    result /= secondNumber;

    return result;
}

Rational operator/(const Rational& firstNumber, const int secondNumber)
{
    Rational result = firstNumber;
    result /= secondNumber;

    return result;
}

Rational operator/(const int firstNumber, const Rational& secondNumber)
{
    Rational result = firstNumber;
    result /= secondNumber;

    return result;
}


//multiplication
Rational& Rational::operator*=(const Rational &number)
{
    _complete *= number._complete;
    _natural *= number._natural;
    normalize();

    return *this;
}

Rational& Rational::operator*=(const int number)
{
    return operator*=(Rational(number));
}

Rational operator*(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational result = firstNumber;
    result *= secondNumber;

    return result;
}

Rational operator*(const Rational& firstNumber, const int secondNumber)
{
    Rational result = firstNumber;
    result *= secondNumber;

    return result;
}

Rational operator*(const int firstNumber, const Rational& secondNumber)
{
    Rational result = firstNumber;
    result *= secondNumber;

    return result;
}




//addition
Rational& Rational::operator+=(const Rational &number)
{
    _complete = _complete*number._natural + number._complete*_natural;
    _natural*=number._natural;
    normalize();

    return *this;

}

Rational& Rational::operator+=(const int number)
{
    return operator+=(Rational(number));
}

Rational operator+(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational result(firstNumber);
    result+= secondNumber;

    return result;
}

Rational operator+(const Rational& firstNumber, const int secondNumber)
{
    Rational result(firstNumber);
    result+= secondNumber;

    return result;
}

Rational operator+(const int firstNumber, const Rational& secondNumber)
{
    Rational result(firstNumber);
    result+= secondNumber;

    return result;
}


//subtraction
Rational& Rational::operator-=(const Rational &number)
{
    _complete = _complete*number._natural - number._complete*_natural;
    _natural*=number._natural;
    normalize();


    return *this;
}

Rational& Rational::operator-=(const int number)
{
    return operator-=(Rational(number));
}

Rational operator-(const Rational& firstNumber, const Rational& secondNumber){
    Rational result = firstNumber;
    result -= secondNumber;

    return result;
}

Rational operator-(const Rational& firstNumber, const int secondNumber)
{
    Rational result = firstNumber;
    result -= secondNumber;

    return result;
}

Rational operator-(const int firstNumber, const Rational& secondNumber)
{
    Rational result = firstNumber;
    result -= secondNumber;

    return result;
}

//Rational& Rational::operator-()
//{
//    _complete *=-1;
//}
//
// Rational operator-()
//{
// return Rational(-1*);
//}


//equality
bool operator==(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational difference = firstNumber - secondNumber;
    return (fabs(difference.toDouble()) < 1E-6);
}

bool operator!=(const Rational& firstNumber, const Rational& secondNumber)
{
    return !(firstNumber==secondNumber);
}

bool operator>=(const Rational& firstNumber, const Rational& secondNumber)
{
    return !(firstNumber<secondNumber);
}

bool operator<=(const Rational& firstNumber, const Rational& secondNumber)
{
    return !(firstNumber>secondNumber);
}

bool operator>(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational number = firstNumber;
    number-=secondNumber;

    return number.isPositive();

}

bool operator<(const Rational& firstNumber, const Rational& secondNumber)
{
    Rational number = firstNumber;
    number-=secondNumber;

    return !number.isPositive();
}

double Rational::toDouble()
{
  return _complete/(double)_natural;
}



void Rational::normalize()
{
    int nod = commonDivivsor(_complete, _natural);
    _complete/=nod;
    _natural/=nod;

     if(_natural < 0)
     {
         _natural*=-1;
         _complete*=-1;
     }
}



bool Rational::isPositive() {
  return (_natural > 0) && (_complete > 0);
}













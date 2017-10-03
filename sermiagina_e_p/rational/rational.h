//
// Created by Елена Сермягина on 21.09.17.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>


class Rational {


public:

    Rational();
    Rational (const int complete);
    Rational(const int complete, const int natural);
   // ~Rational() = default;


    //operators
    Rational& operator+=(const Rational& number);
    Rational& operator+=(const int number);
    Rational& operator-=(const Rational& number);
    Rational& operator-=(const int number);
    Rational& operator/=(const Rational& number);
    Rational& operator/=(const int number);
    Rational& operator*=(const Rational& number);
    Rational& operator*=(const int number);
    Rational& operator-();

    bool isPositive();

    std::ostream& writeTo(std::ostream& ostrm) const;
    //std::istream& readFrom(std::istream& istrm);
    double toDouble();


private:

    int _complete {0};
    int _natural{1};

    int commonDivivsor(int firstNumber, int secondNumber);
    //int leastCommonMultiple(int firstNUmber, int secondNumber);
    void normalize();


};

Rational operator+(const Rational& firstNumber, const Rational& secondNumber);
Rational operator+(const Rational& firstNumber, const int secondNumber);
Rational operator+(const int firstNumber, const Rational& secondNumber);

Rational operator-(const Rational& firstNumber, const Rational& secondNumber);
Rational operator-(const Rational& firstNumber, const int secondNumber);
Rational operator-(const int firstNumber, const Rational& secondNumber);

Rational operator/(const Rational& firstNumber, const Rational& secondNumber);
Rational operator/(const Rational& firstNumber, const int secondNumber);
Rational operator/(const int firstNumber, const Rational& secondNumber);

Rational operator*(const Rational& firstNumber, const Rational& secondNumber);
Rational operator*(const Rational& firstNumber, const int secondNumber);
Rational operator*(const int firstNumber, const Rational& secondNumber);

bool operator==(const Rational& firstNumber, const Rational& secondNumber);
bool operator!=(const Rational& firstNumber, const Rational& secondNumber);
bool operator>=(const Rational& firstNumber, const Rational& secondNumber);
bool operator<=(const Rational& firstNumber, const Rational& secondNumber);
bool operator>(const Rational& firstNumber, const Rational& secondNumber);
bool operator<(const Rational& firstNumber, const Rational& secondNumber);




std::ostream& operator<<(std::ostream& ostr, Rational number);


#endif //RATIONAL_RATIONAL_H
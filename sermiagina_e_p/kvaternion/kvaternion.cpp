//
// Created by Елена Сермягина on 19.10.2017.
//
#include <iostream>
#include <sstream>
#include "kvaternion.h"
#include <cmath>

using namespace std;

Kvaternion::Kvaternion( const double _i1, const double _i2, const double _j1, const double _j2):
   i11(_i1),
   i12(_i2),
   i21(_j1),
   i22(_j2)
{

}

//копир
Kvaternion::Kvaternion(const Kvaternion& kva):
i11(kva.i11),
i12(kva.i12),
i21(kva.i21),
i22(kva.i22){}

Kvaternion& Kvaternion::operator=(const Kvaternion& kva)
{
    i11 = kva.i11;
    i12 = kva.i12;
    i21 = kva.i21;
    i22 = kva.i22;

    return *this;
}

std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
    ostrm << "{" << i11 << "," << i12 << "}" << "{" << i21 << "," << i22 << "}";
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, Kvaternion kva)
{
    return kva.writeTo(ostr);
}


Kvaternion& Kvaternion::operator*=(const Kvaternion& kva)
{
    i11 = i11 * kva.i11 + i12 * kva.i21;
    i21 = i21 * kva.i11 + i22 * kva.i21;
    i12 = i11 * kva.i12 + i12 * kva.i22;
    i22 = i21 * kva.i12 + i22 * kva.i22;

    return *this;

}

Kvaternion& Kvaternion::operator*=( double number)
{
    i11*=number;
    i12*=number;
    i21*=number;
    i22*=number;

    return *this;
}

Kvaternion& Kvaternion::operator+=(const Kvaternion& kva)
{
    i11+=kva.i11;
    i12+=kva.i12;
    i21+=kva.i21;
    i22+=kva.i22;

    return *this;
}

Kvaternion& Kvaternion::operator-=(const Kvaternion& kva)
{
    i11-=kva.i11;
    i12-=kva.i12;
    i21-=kva.i21;
    i22-=kva.i22;

    return *this;
}

double Kvaternion::Determinator()
{
    return(i11*i22 - i12*i21);
}

double Kvaternion::Magnitude()
{
    return sqrt(i11*i11 + i12*i12 + i21*i21 + i22*i22);
}

double Kvaternion::innerProduct(const Kvaternion& kva)
{
    return(i11*kva.i11 + i12*kva.i12 + i21*kva.i21 + i22*kva.i22);
}

Kvaternion operator+(const Kvaternion& firstKva, const Kvaternion& secondKva)
{
    Kvaternion temp(firstKva);
    return temp+=secondKva;
}

Kvaternion operator-(const Kvaternion& firstKva, const Kvaternion& secondKva)
{
    Kvaternion temp(firstKva);
    return temp-=secondKva;
}

Kvaternion operator*(const Kvaternion& firstKva, const double secondNumber)
{
    Kvaternion temp(firstKva);
    return temp*=secondNumber;
}
Kvaternion operator*(const double firstNumber, const Kvaternion& secondKva)
{
    Kvaternion temp(secondKva);
    return temp*=firstNumber;
}
//
// Created by Елена Сермягина on 19.10.2017.
//
#include <iostream>
#include <sstream>
#include "kvaternion.h"

using namespace std;

Kvaternion::Kvaternion( const double _i1, const double _i2, const double _j1, const double _j2):
   i11(_i1),
   i12(_i2),
   i21(_j1),
   i22(_j2)
{

}

//копир
Kvaternion::Kvaternion(Kvaternion& kva):
i11(kva.i11),
i12(kva.i12),
i21(kva.i21),
i22(kva.i22){}



std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
    ostrm << "{" << i11 << "," << i12 << "}, " << "{" << i21 << "," << i22 << "}";
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, Kvaternion kva)
{
    return kva.writeTo(ostr);
}


Kvaternion& Kvaternion::operator*=(Kvaternion& kva)
{
    i11 = i11*kva.i11 + i12 * kva.i21;
    i21 = i21*kva.i11 + i22* kva.i21;
    i12 = i11 * kva.i12 + i12 * kva.i22;
    i22 = i21 * kva.i12 + i22 * kva.i22;

    return *this;

}

double Kvaternion::Determinator(Kvaternion& kva)
{
    return(i11*i22 - i12*i21);
}




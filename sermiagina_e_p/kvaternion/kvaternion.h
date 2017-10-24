 //
// Created by Елена Сермягина on 19.10.2017.
//

#ifndef KVATERNION_KVATERNION_H
#define KVATERNION_KVATERNION_H

#include <iosfwd>

struct Kvaternion
{
    Kvaternion() = default;
    ~Kvaternion() = default;
    Kvaternion( const double _i1, const double _i2, const double _j1, const double _j2);
    Kvaternion(const Kvaternion& kva);

    double i11{0.0};
    double i12{0.0};
    double i21{0.0};
    double i22{0.0};

    Kvaternion& operator=(const Kvaternion& kva);
    Kvaternion& operator*=(const Kvaternion& kva);
    Kvaternion& operator*=(const double number);
    Kvaternion& operator+=(const Kvaternion& kva);
    Kvaternion& operator-=(const Kvaternion& kva);
    double Determinator();
    double Magnitude();
    double innerProduct(const Kvaternion& kva);


    std::ostream& writeTo(std::ostream& ostrm) const;



};

std::ostream& operator<<(std::ostream& ostr, Kvaternion kva);

 Kvaternion operator+(const Kvaternion& firstVector, const Kvaternion& secondVector);

 Kvaternion operator-(const Kvaternion& firstVector, const Kvaternion& secondVector);

 Kvaternion operator*(const Kvaternion& firstVector, const double secondNumber);
 Kvaternion operator*(const double firstNumber, const Kvaternion& secondVector);

#endif //KVATERNION_KVATERNION_H


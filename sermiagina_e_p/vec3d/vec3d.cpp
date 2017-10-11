//
// Created by Елена Сермягина on 05.10.2017.
//
#include "vec3d.h"
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;


Vec3d::Vec3d(const double x, const double y, const double z)
        : _x(x),
          _y(y),
          _z(z)
{

}

//конструктор копирования
Vec3d::Vec3d(const Vec3d& v)
        : _x(v._x),
          _y(v._y),
          _z(v._z)
{

}

Vec3d Vec3d::operator=(const Vec3d& v)
{
    _x = v._x;
    _y = v._y;
    _z = v._z;

    return *this;
}

std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
    ostrm << "(" << _x << ", " << _y << ", " << _z << ")";
    return ostrm;
}

//std::istream& readFrom(std::istream& istrm) const
//{}

std::ostream& operator<<(std::ostream& ostr, Vec3d vector)
{
    return vector.writeTo(ostr);
}

//std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
//{
//    return rhs.readFrom(istrm);
//}



Vec3d& Vec3d::operator+=(const Vec3d& vector)
{
    _x += vector._x;
    _y += vector._y;
    _z += vector._z;

    return *this;
}

Vec3d& Vec3d::operator-=(const Vec3d& vector)
{
    _x -= vector._x;
    _y -= vector._y;
    _z -= vector._z;

    return *this;
}

Vec3d& Vec3d::operator*=(const Vec3d& vector)
{
    _x *= vector._x;
    _y *= vector._y;
    _z *= vector._z;

    return *this;
}

Vec3d& Vec3d::operator/=(const Vec3d& vector)
{
    _x /= vector._x;
    _y /= vector._y;
    _z /= vector._z;

    return *this;
}

Vec3d& Vec3d::operator*=(const double number)
{
    _x *= number;
    _y *= number;
    _z *= number;

    return *this;
}

Vec3d& Vec3d::operator/=(const double number)
{
    _x /= number;
    _y /= number;
    _z /= number;

    return *this;
}


Vec3d& Vec3d::operator-()
{
   // Vec3d temp = *this;
    *this*=-1;
    return *this;
}

double Vec3d::vectorLength()
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}

double Vec3d::scalarProduct(const Vec3d& vector)
{
    double scalar = vector._x * _x + vector._y*_y + vector._z * _z;
    return scalar;
}

Vec3d Vec3d::vectorProduct(const Vec3d& vector)
{
    //a × b = {aybz - azby; azbx - axbz; axby - aybx}
    Vec3d temp(_y * vector._z - _z * vector._y, _z * vector._x - _x*vector._z, _x*vector._y - _y*vector._x);
    return temp;
}


bool Vec3d::operator==(const Vec3d& vector) const
{
    return fabs(_x - vector._x)&&fabs( _y - vector._y)&&fabs(_x - vector._x) < e;
}

bool Vec3d::operator!=(const Vec3d& vector) const
{
    return !operator==(vector);
}

Vec3d operator+(const Vec3d& firstVector, const Vec3d& secondVector)
{
//    Vec3d temp(firstVector._x + secondVector._x, firstVector._y + secondVector._y, firstVector._z + secondVector._z);
//    return temp;
    Vec3d temp(firstVector);
    return temp+=secondVector;
}

Vec3d operator-(const Vec3d& firstVector, const Vec3d& secondVector)
{
    Vec3d temp(firstVector);
    return temp-=secondVector;
}

Vec3d operator*(const Vec3d& firstVector, const double secondNumber)
{
    Vec3d temp(firstVector);
    return temp*=secondNumber;
}

Vec3d operator*(const double firstNumber, const Vec3d& secondVector)
{
    Vec3d temp(secondVector);
    return temp*=firstNumber;
}

Vec3d operator/(const Vec3d& firstVector, const double secondNumber)
{
    Vec3d temp(firstVector);
    return temp/=secondNumber;
}

//Vec3d operator/(const double firstNumber, const Vec3d& secondVector)
//{
//    Vec3d temp(secondVector);
//    return temp/=firstNumber;
//}

//
// Created by Елена Сермягина on 11.10.2017.
//

#ifndef VEC3DT_VEC3DT_H
#define VEC3DT_VEC3DT_H

#include <iosfwd>
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

template<typename T>
struct Vec3dT

{

public:


    Vec3dT() = default;
    ~Vec3dT() = default;
    Vec3dT(const T x, const T y, const T z);
    Vec3dT(const Vec3dT& v);
    T _x{T()};
    T _y{T()};
    T _z{T()};
    const double e = 10E-6;

    Vec3dT<T>& operator+=(const Vec3dT<T>& vector);

    Vec3dT<T>& operator-=(const Vec3dT<T>& vector);


    Vec3dT<T>& operator*=(const T number);


    Vec3dT<T>& operator/=(const T number);

    Vec3dT<T>& operator=(const Vec3dT<T>& v);

    bool operator==(const Vec3dT<T>& vector) const;
    bool operator!=(const Vec3dT<T>& vector) const;

    double vectorLength();
    double scalarProduct(const Vec3dT<T>& vector);
    Vec3dT<T>  vectorProduct(const Vec3dT<T>& vector);

    Vec3dT<T>& operator-();

    std::ostream& writeTo(std::ostream& ostrm) const;


};

template<typename T>
Vec3dT<T>::Vec3dT(const T x, const T y, const T z)
        : _x(x),
          _y(y),
          _z(z)
{

}

template<typename T>
Vec3dT<T>::Vec3dT(const Vec3dT& v)
        : _x(v._x),
          _y(v._y),
          _z(v._z)
{

}



template<typename T>
Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT<T>& vector)
{
    _x += vector._x;
    _y += vector._y;
    _z += vector._z;

    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT<T>& vector)
{
    _x -= vector._x;
    _y -= vector._y;
    _z -= vector._z;

    return *this;
}



template<typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const T number)
{
    _x *= number;
    _y *= number;
    _z *= number;

    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator/=(const T number)
{
    _x /= number;
    _y /= number;
    _z /= number;

    return *this;
}





template<typename T>
Vec3dT<T> operator+(const Vec3dT<T>& firstVector, const Vec3dT<T>& secondVector)
{
    Vec3dT<T> temp(firstVector);
    return temp+=secondVector;
}

template<typename T>
Vec3dT<T> operator-(const Vec3dT<T>& firstVector, const Vec3dT<T>& secondVector)
{
    Vec3dT<T> temp(firstVector);
    return temp-=secondVector;
}

template<typename T>
Vec3dT<T> operator*(const Vec3dT<T>& firstVector, const T secondNumber)
{
    Vec3dT<T> temp(firstVector);
    return temp*=secondNumber;
}

template<typename T>
Vec3dT<T> operator*(const T firstNumber, const Vec3dT<T>& secondVector)
{
    Vec3dT<T> temp(secondVector);
    return temp*=firstNumber;
}

template<typename T>
Vec3dT<T> operator/(const Vec3dT<T>& firstVector, const T secondNumber)
{
    Vec3dT<T> temp(firstVector);
    return temp/=secondNumber;
}



template<typename T>
std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << "(" << _x << ", " << _y << ", " << _z << ")";
    return ostrm;
}

template<typename T>
std::ostream& operator<<(std::ostream& ostr, Vec3dT<T> vector)
{
    return vector.writeTo(ostr);
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator=(const Vec3dT<T>& v)
{
    _x = v._x;
    _y = v._y;
    _z = v._z;

    return *this;
}
//
//template<typename T>
//Vec3dT<T>& Vec3dT<T>::operator-()
//{
//
//    *this *= -1;
//    return *this;
//}

template<typename T>
double Vec3dT<T>::vectorLength()
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}

template<typename T>
double Vec3dT<T>::scalarProduct(const Vec3dT<T>& vector)
{
    double scalar = vector._x * _x + vector._y*_y + vector._z * _z;
    return scalar;
}

template<typename T>
Vec3dT<T> Vec3dT<T>::vectorProduct(const Vec3dT<T>& vector)
{
    //a × b = {aybz - azby; azbx - axbz; axby - aybx}
    Vec3dT temp(_y * vector._z - _z * vector._y, _z * vector._x - _x*vector._z, _x*vector._y - _y*vector._x);
    return temp;
}

template<typename T>
bool Vec3dT<T>::operator==(const Vec3dT<T>& vector) const
{
    return (fabs(_x - vector._x < e))&&(fabs(_y - vector._y < e))&&(fabs(_z - vector._z < e));
}

template<typename T>
bool Vec3dT<T>::operator!=(const Vec3dT<T>& vector) const
{
    return !operator==(vector);
}


#endif //VEC3DT_VEC3DT_H

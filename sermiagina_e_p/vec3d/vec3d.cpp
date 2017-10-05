//
// Created by Елена Сермягина on 05.10.2017.
//
#include "vec3d.h"
#include <sstream>
#include <iostream>

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
    ostrm << "{" << _x << "," << _y << "," << _z << "}";
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, Vec3d vector)
{
    return vector.writeTo(ostr);
}

Vec3d& Vec3d::operator+=(const Vec3d& vector)
{
    _x = _x + vector._x;
    _y = _y + vector._y;
    _z = _z + vector._z;

    return *this;
}


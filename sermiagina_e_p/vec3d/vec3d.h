//
// Created by Елена Сермягина on 05.10.2017.
//

#ifndef VEC3D_VEC3D_H
#define VEC3D_VEC3D_H

#include <iosfwd>

struct Vec3d
{

public:

    Vec3d() = default;
    ~Vec3d() = default;
    Vec3d(const double x, const double y, const double z);
    //констуктор копирования
    //при передаче по значению и при возврате по значению
    Vec3d(const Vec3d& v);
    //оператор присваивания возвращает ссылку на экземпляр (на самомго себя)
    Vec3d operator=(const Vec3d& v);

    double _x{0.0};
    double _y{0.0};
    double _z{0.0};
    const double e = 1E-6;

    //==
    //!=
    // - + * / на число
    //скалярное векторное
    //длина вектора

    Vec3d& operator+=(const Vec3d& vector);

    Vec3d& operator-=(const Vec3d& vector);

    Vec3d& operator*=(const Vec3d& vector);
    Vec3d& operator*=(const double number);

    Vec3d& operator/=(const Vec3d& vector);
    Vec3d& operator/=(const double number);

    bool operator==(const Vec3d& vector) const;
    bool operator!=(const Vec3d& vector) const;

    double vectorLength();
    double scalarProduct(const Vec3d& vector);
    Vec3d  vectorProduct(const Vec3d& vector);

    Vec3d& operator-();


   // std::istream& readFrom(std::istream& istrm) const;
    std::ostream& writeTo(std::ostream& ostrm) const;
};

Vec3d operator+(const Vec3d& firstVector, const Vec3d& secondVector);

Vec3d operator-(const Vec3d& firstVector, const Vec3d& secondVector);

Vec3d operator*(const Vec3d& firstVector, const double secondNumber);
Vec3d operator*(const double firstNumber, const Vec3d& secondVector);

Vec3d operator/(const Vec3d& firstVector, const double secondNumber);
//Vec3d operator/(const double firstNumber, const Vec3d& secondVector);


//std::istream& operator >> (std::istream& istrm, Vec3d& rhs);
std::ostream& operator<<(std::ostream& ostr, Vec3d vector);

#endif //VEC3D_VEC3D_H

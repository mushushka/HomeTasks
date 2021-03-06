//
// Created by Елена Сермягина on 21.09.17.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>

struct Complex {

    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    Complex& operator+=(const Complex& rhs);
    Complex& operator +=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);



    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);


    double e = 1E-6;
    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
};

 std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
 std::istream& operator>>(std::istream& istrm, Complex& rhs);

 Complex operator+(const Complex& lhs, const Complex& rhs);
 Complex operator+(const Complex& lhs, const double rhs);
 Complex operator+(const double rhs, const Complex& lhs);


 Complex operator-(const Complex& lhs, const Complex& rhs);
 Complex operator-(const Complex& lhs, const double rhs);
 Complex operator-(const double rhs, const Complex& lhs);

 Complex operator*(const Complex& lhs, const Complex& rhs);
 Complex operator*(const Complex& lhs, const double rhs);
 Complex operator*(const double rhs, const Complex& lhs);

 Complex operator/(const Complex& lhs, const double rhs);
 Complex operator/(const Complex& lhs, const Complex& rhs);
 Complex operator/(const double rhs, const Complex& lhs);




#endif //COMPLEX_COMPLEX_H

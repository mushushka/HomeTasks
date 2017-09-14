#include <iostream>
#include <sstream>

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
    Complex& operator+=(const Complex& rhs);
    Complex& operator +=(const double rhs) { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs) { return operator*=(Complex(rhs));}
        std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);



    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
};

Complex operator+(const Complex& lhs, const Complex& rhs)
{

    return Complex(rhs.re + lhs.re, lhs.im + rhs.im );
};
Complex operator-(const Complex& lhs, const Complex& rhs)
{
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);

}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success:" << str << " -> " << z << endl;
    } else {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();


}

int main()
{
    using namespace std;

    Complex z;
    cout << "Initial complex number: " << z;
    z += Complex(8.0);
    cout << "8.0 added: " << z;
    z -= Complex(3.0, -4);

    cout << z;
    z -= 6.0;
    cout << z;
    z *= 6.0;
    cout << z;
   // testParse("{8.9,9}");
   // testParse("{8.9, 9}");
   // testParse("{8.9,9");

    //сделать понятно

    return 0;
}

Complex::Complex(const double real)
        : Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary)
        : re(real)
        , im(imaginary)
{

}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    Complex z = Complex(-rhs.re, -rhs.im);

    return operator+=(z);
}

Complex&  Complex::operator*=(const Complex& rhs)
{
    re = (re*rhs.re) - (im*rhs.im);
    im = (re*rhs.im) + (im*rhs.re);
    return *this;

}



std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace << '\n';
    return ostrm;

}

std::istream& Complex::readFrom(std::istream &istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
                && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaginary;

        } else {
            istrm.setstate(std::ios_base::failbit);
        }

    }
    return istrm;
}


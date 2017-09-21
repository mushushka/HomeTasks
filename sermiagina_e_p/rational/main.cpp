#include <iostream>
#include <sstream>
//#include <stdexcept>


using namespace std;

class Rational {

public:
    ~Rational() = default;
    Rational() {}
    Rational (const int complete): _complete(complete){}

    Rational(const int complete, const int natural)
            : _complete(complete),
              _natural(natural)
    {
        if (_natural == 0) {

           throw invalid_argument("Zero in natural");
        }
        normalize();
        commonDivivsor(_complete, _natural);
    }

    //operators
    Rational& operator+=(const Rational& number);
    Rational& operator-=(const Rational& number);
    Rational& operator/=(const Rational& number);
    Rational& operator*=(const Rational& number);

    bool isPositive();

    std::ostream& writeTo(std::ostream& ostrm) const;
    //std::istream& readFrom(std::istream& istrm);


private:

    int _complete {0};
    int _natural{1};


//реализация нормализации
   int commonDivivsor(int firstNumber, int secondNumber) {

        while (firstNumber && secondNumber) {
            if (abs(firstNumber) > abs(secondNumber)) {
                firstNumber = abs(firstNumber % secondNumber);
            } else {
                secondNumber = abs(secondNumber % firstNumber);
            }

        }
        return (firstNumber + secondNumber);
    }

    void normalize();


};



std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << _complete << "/" << _natural;
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, Rational number)
{
    return number.writeTo(ostr);
}


Rational& Rational::operator/=(const Rational &number) {

    _complete *= number._natural;
    _natural *= number._complete;
    normalize();

    return *this;
}


Rational& Rational::operator*=(const Rational &number) {
    _complete *= number._complete;
    _natural *= number._natural;
    normalize();

    return *this;
}

Rational& Rational::operator+=(const Rational &number) {
    _complete = _complete*number._natural + number._complete*_natural;
    _natural*=number._natural;
    normalize();

    return *this;

}

Rational& Rational::operator-=(const Rational &number) {
    _complete = _complete*number._natural - number._complete*_natural;
    _natural*=number._natural;
    normalize();


    return *this;
}


void Rational::normalize() {
    int nod = commonDivivsor(_complete, _natural);
    _complete/=nod;
    _natural/=nod;
}



bool Rational::isPositive() {
    return (_natural > 0) && (_complete > 0);
}


//operators
Rational operator+(const Rational& firstNumber, const Rational& secondNumber);
Rational operator-(const Rational& firstNumber, const Rational& secondNumber);
Rational operator/(const Rational& firstNumber, const Rational& secondNumber);
Rational operator*(const Rational& firstNumber, const Rational& secondNumber);

Rational operator+(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result+= secondNumber;

    return result;
}

Rational operator-(const Rational& firstNumber, const Rational& secondNumber){
    Rational result = firstNumber;
    result -= secondNumber;

    return result;
}

Rational operator*(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result *= secondNumber;

    return result;
}

Rational operator/(const Rational& firstNumber, const Rational& secondNumber) {
    Rational result = firstNumber;
    result /= secondNumber;

    return result;
}



int main() {

    using namespace std;

   // int a = -7;
   // int b = 3;
   // int c = a%b;

    Rational num = Rational(3,6);
    std::cout <<" Initial number = " << num << std::endl;

    Rational num1 = Rational(10,2);
    std::cout <<" Initial number = " << num1 << std::endl;

    num1/=num;

    std::cout <<"Number *= " << num1 << std::endl;

    std::cout <<"Number " << num << std::endl;
    num/=(1,2);
    std::cout <<"Number /= 1/2 " << num << std::endl;

   // std::cout <<"Num = " << num << std::endl;


  //  std::cout <<"Number / 10 = " << num << std::endl;
    Rational num2 = Rational(1,0);
    std::cout <<"Number  " << num2 << std::endl;


    return 0;
}








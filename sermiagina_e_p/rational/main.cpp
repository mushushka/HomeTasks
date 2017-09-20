#include <iostream>
#include <sstream>
//#include <stdexcept>


using namespace std;

class Rational {

public:

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
    ~Rational() = default;

//реализация нормализации
   int commonDivivsor(int firstNumber, int secondNumber) {

        while (firstNumber && secondNumber) {
            if (firstNumber > secondNumber) {
                firstNumber = firstNumber % secondNumber;
            } else {
                secondNumber = secondNumber % firstNumber;
            }

        }
        return (firstNumber + secondNumber);
    }

    void normalize();


};


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



int main() {

    using namespace std;

   // Rational num = Rational(3,6);


    std::cout << "dfdfd" << std::endl;
    return 0;
}








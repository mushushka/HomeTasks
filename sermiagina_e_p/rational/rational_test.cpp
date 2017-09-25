//
// Created by Елена Сермягина on 21.09.17.
//
#include "rational.h"


#include <iostream>

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

//
// Created by Елена Сермягина on 05.10.2017.
//

#include "vec3d.h"
#include<sstream>
#include <iostream>

using namespace std;

void equalityTest(Vec3d first, Vec3d second)
{
    Vec3d one(first);
    Vec3d two(second);

    cout << endl << "First vector: " << one << endl;
    cout << "Second vector: " << two << endl;

    cout << endl << "Equality test: " << endl << endl;

    cout << one << " is equal to " << two << " ? " << (one == two) << endl;
    cout << one << " isn't equal to " << two << " ? " << (one != two) << endl;

    cout << endl << "Vice versa: " << endl;

    cout << two << " is equal to " << one << " ? " << (one == two) << endl;
    cout << two << " isn't equal to " << one << " ? " << (one != two) << endl << endl;

    cout <<  "____________________________________________" << endl << endl;


}

void mathTest(Vec3d first, Vec3d second) {

    cout << endl << "Math tests:"<< endl;

    Vec3d one(first);
    Vec3d two(second);

    cout << endl << "First vector: " << one << endl;
    cout << "Second vector: " << two << endl;

    cout << endl << "Length of " << one << " = " << one.vectorLength() << endl;
    cout << endl << "Vector product " << one << " x " << two << " = " << one.vectorProduct(two) << endl;
    cout << endl << "Scalar product " << one << " * " << two << " = " << one.scalarProduct(two) << endl;

    cout <<  endl << "Plus to minus or minus to plus:" << endl;
    cout << "one = " << one << "; -one = ";
    cout << -one << endl;
    cout << "two = " << two << "; -two = ";
    cout << -two << endl;




    cout << endl << "Vec3d and Vec3d:" << endl;
    cout << one << " + " << two << " = " << (one + two) << endl;
    cout << one << " - " << two << " = " << (one - two) << endl << endl;


    cout << "Vec3d and Double:" << endl;
    cout << one << " * " << 7 << " = " << (one * 7.0) << endl;
    cout << one << " / " << 2 << " = " << (one / 2.0) << endl << endl;

    cout << "Double and Vec3d:" << endl;
    cout << one << " * " << 7 << " = " << (7.0 * one) << endl << endl;




    cout << "one = " << one << "; one += (7.0, 2.0, 5.0); one = ";
    one += Vec3d{7.0, 2.0, 5.0};
    cout << one << endl;

    cout << "one = " << one << "; one -= (4.111111, 2.0, 0); one = ";
    one -= Vec3d{4.111111, 2.0, 0};
    cout << one << endl;


    cout << "one = " << one << "; one *= 3; one = ";
    one *= 3.0;
    cout << one << endl;

    cout << "one = " << one << "; one /= 4; one = ";
    one /= 4.0;
    cout << one << endl;

    cout <<  "____________________________________________" << endl << endl;


}




int main() {

   // std::cout << "Hello, World!" << std::endl;

    equalityTest({1.1, 1.2, 1.22224},{1.1, 1.2, 1.22221});
    equalityTest({-5.0, 1.0, 1.0},{5.0, 1.0, 1.0});
    equalityTest({-5.0, 1.0, 1.0},{-5.0, 1.0, 1.0});

    mathTest({1.0, 2.0, 4.0},{22.0, 1.2, 8.0});






    return 0;
}
//
// Created by Елена Сермягина on 11.10.2017.
//

#include "vec3dT.h"
#include <sstream>
#include <iostream>

using namespace std;


template<typename T>
void equalityTest(Vec3dT<T> first, Vec3dT<T> second)
{
    Vec3dT<T> one(first);
    Vec3dT<T> two(second);

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

template<typename T>
void mathTest(Vec3dT<T> first, Vec3dT<T> second) {

    cout << endl << "Math tests:"<< endl;

    Vec3dT<T> one(first);
    Vec3dT<T> two(second);

    cout << endl << "First vector: " << one << endl;
    cout << "Second vector: " << two << endl;

    cout << endl << "Length of " << one << " = " << one.vectorLength() << endl;
    cout << endl << "Vector product " << one << " x " << two << " = " << one.vectorProduct(two) << endl;
    cout << endl << "Scalar product " << one << " * " << two << " = " << one.scalarProduct(two) << endl;

//    cout <<  endl << "Plus to minus or minus to plus:" << endl;
//    cout << "one = " << one << "; -one = ";
//    cout << -one << endl;
//    cout << "two = " << two << "; -two = ";
//    cout << -two << endl;




    cout << endl << "Vec3d and Vec3d:" << endl;
    cout << one << " + " << two << " = " << (one + two) << endl;
    cout << one << " - " << two << " = " << (one - two) << endl << endl;


    cout << "Vec3d and Double:" << endl;
    cout << one << " * " << 7 << " = " << (one * 7) << endl;
    cout << one << " / " << 2 << " = " << (one / 2) << endl << endl;

    cout << "Double and Vec3d:" << endl;
    cout << one << " * " << 7 << " = " << (7 * one) << endl << endl;




    cout << "one = " << one << "; one += (7, 2, 5); one = ";
    one += Vec3dT<T>{7, 2, 5};
    cout << one << endl;

    cout << "one = " << one << "; one -= (4, 2, 0); one = ";
    one -= Vec3dT<T>{4, 2, 0};
    cout << one << endl;


    cout << "one = " << one << "; one *= 3; one = ";
    one *= 3;
    cout << one << endl;

    cout << "one = " << one << "; one /= 4; one = ";
    one /= 4;
    cout << one << endl;

    cout <<  "____________________________________________" << endl << endl;


}



int main() {


    Vec3dT<double> vec1;
    cout << endl << "Empty constructor: " << vec1 << endl;

    Vec3dT<double> vec2(2.0, 3.0, 1.0);
    cout << "Constructor with 3 parameters: "<< vec2 << endl;

    Vec3dT<double> vec3(vec2);
    cout << "Copying constructor: "<< vec3 << endl;

    mathTest(Vec3dT<int>(4, 5, 2), Vec3dT<int>(1, 8, 62));
    //mathTest(Vec3dT<double>(4.0, 5.0, 2.0), Vec3dT<double>(1.0, 8.0, 62.2));
    equalityTest(Vec3dT<double>{1.1, 1.2, 1.22224},Vec3dT<double>{1.1, 1.2, 1.22221});
    equalityTest(Vec3dT<double>{-5.0, 1.0, 1.0},Vec3dT<double>{5.0, 1.0, 1.0});
    equalityTest(Vec3dT<double>{-5.0, 1.0, 1.0},Vec3dT<double>{-5.0, 1.0, 1.0});






    return 0;
}

//
// Created by Елена Сермягина on 05.10.2017.
//

#include "vec3d.h"
#include<sstream>
#include <iostream>

using namespace std;

int main() {

    std::cout << "Hello, World!" << std::endl;

    Vec3d a(1.0, 2.0, 3.0);
    Vec3d b;
    Vec3d с(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    //std::cout << c << std::endl;

    return 0;
}
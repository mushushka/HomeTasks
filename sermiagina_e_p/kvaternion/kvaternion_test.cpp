//
// Created by Елена Сермягина on 19.10.2017.
//

#include <iostream>
#include <sstream>
#include "kvaternion.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Kvaternion cv(2.0, 3.0, 4.0, 5.0);
    Kvaternion c();
    Kvaternion cva(cv);

    Kvaternion kv(2.0, 3.0, 4.0, 6.0);


   // c = {3.0, 2.0, 1.0, 2.0};


   // std::cout << c << std::endl;
   // std::cout << cv << std::endl;
    return 0;
}

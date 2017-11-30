//
// Created by Елена Сермягина on 28.11.2017.
//
#include "stack.h"
#include <iostream>

using namespace std;


int main() {

    Stack stack;
    stack.push('a');
    stack.push('c');
    stack.push('v');
    stack.push('x');
    stack.push('l');
    stack.push('u');
    cout << "Stack" << endl << stack << endl;

    stack.pop();
    cout << "Stack and pop" << endl << stack << endl;

    Stack stack2;
    stack2.push('b');
    stack2.push('x');
    stack2.push('a');
    stack2.push('w');
    stack2.push('q');
    stack2.push('r');
    cout << "Stack2" << endl << stack2 << endl;


    stack2 = stack;
    cout << "Stack2 = stack" << endl << stack2 << endl;


     Stack stack3;
    try {
        stack3.top();
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }


    return 0;
}

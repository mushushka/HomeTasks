//
// Created by Елена Сермягина on 06.12.2017.
//

#include "stackA.h"
#include <iostream>

using namespace std;

StackA::StackA() :
        size{1},
        data{new int[size]} {
}

StackA::~StackA() {
    delete[] data;
    data = nullptr;
}

bool StackA::isEmpty() const {
    return (iTop == 0);
}

void StackA::push(const int element) {
    if (iTop == size - 1 ) {
        int *pNewData{new int[size * 2]};
        for (int i = 0; i < size; i += 1) {
            pNewData[i] = data[i];
        }
        size *= 2;
        delete[] data;
        data = pNewData;

    }
    data[iTop] = element;
    iTop++;
}

int StackA::top() const {
    if (isEmpty()) {
        throw invalid_argument("No top element, array is empty");
    }
    return data[iTop];
}

void StackA::pop() {
    if (isEmpty()) {
        throw invalid_argument("Stack is empty");
    }

    iTop -= 1;
}

std::ostream &StackA::writeTo(std::ostream &ostrm) const {
    ostrm << "[ ";
    for (ptrdiff_t i = 0; i <= iTop; i += 1) {
        ostrm << data[i];
        if (i < iTop) {
            ostrm << ", ";
        }

    }
    ostrm << " ]";
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, const StackA &stack) {
    return stack.writeTo(ostrm);
}
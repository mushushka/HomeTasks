//
// Created by Елена Сермягина on 06.12.2017.
//

#ifndef STACKA_STACKA_H
#define STACKA_STACKA_H

#include <iosfwd>


class StackA {
public:
    StackA();

    ~StackA();

    StackA(const StackA &copyArray);

    void push(const int element);

    void pop();

    int top() const;

    bool isEmpty() const;

    StackA& operator=(const StackA &copyArray);

    std::ostream &writeTo(std::ostream &ostrm) const;


private:
    int iTop{0};
    int size{0};
    int *data{nullptr};
};

std::ostream &operator<<(std::ostream &ostream, const StackA& stack);

#endif //STACKA_STACKA_H

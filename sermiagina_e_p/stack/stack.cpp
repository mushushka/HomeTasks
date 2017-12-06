//
// Created by Елена Сермягина on 16.11.2017.
//
//создать память, кто будет за ним, указатель на голову на него
//если стек пусток то ТОР делать нельзя , если стек пустой сроу инвалид
//при копировании построить вторую цепочку аналогичную первой
//pCopyFrom = pCopyFrom -> pNext;
// pCopyTo -> pNext = new Node();
#include <iostream>
#include "stack.h"

using namespace std;

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

Stack::Stack(const Stack &copyStack) {
    // Stack Stacky;
//    Node *pCopyFrom(copyStack.pHead_);
//    Node *pCopyTo();
//    while (pCopyFrom != nullptr) {
//        push(pCopyFrom->data_);
//        pCopyFrom = pCopyFrom->pNext_;
//    }
    //  pCopyFrom = pCopyFrom->pNext_;
    //   pCopyTo -> pNext = new Node(nullptr,value );
    Node *pCopyFrom(copyStack.pHead_->pNext_);
    Node *pCopyTo = new Node(nullptr, copyStack.pHead_->data_);
    pHead_ = pCopyTo;
    while (pCopyFrom != nullptr) {
        pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }
}

Stack &Stack::operator=(const Stack &copyStack) {
    Node *pCopyFrom(copyStack.pHead_);
    Node *pCopyTo(pHead_);

    while (pCopyFrom->pNext_ != nullptr && pCopyTo->pNext_ != nullptr) {

        pCopyTo->data_ = pCopyFrom->data_;
        pCopyFrom = pCopyFrom->pNext_;
        pCopyTo = pCopyTo->pNext_;
    }
    
    if (pCopyFrom->pNext_ == nullptr && pCopyTo->pNext_ != nullptr) {
        pCopyTo->data_ = pCopyFrom->data_;
        Node *pDeleted;
        while (pCopyTo->pNext_ != nullptr) {
            pDeleted = pCopyTo->pNext_;
            pCopyTo->pNext_ = pDeleted->pNext_;
            delete pDeleted;
        }
    }

    if (pCopyTo->pNext_ == nullptr && pCopyFrom->pNext_ != nullptr) {
        pCopyTo->data_ = pCopyFrom->data_;
        pCopyFrom = pCopyFrom->pNext_;
        while (pCopyFrom != nullptr) {
            pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
            pCopyTo = pCopyTo->pNext_;
            pCopyFrom = pCopyFrom->pNext_;
        }
    }




    return *this;
}

Stack::Node::Node(Node *pNext) :
        pNext_(pNext),
        data_(char(0)) {

}

Stack::Node::Node(Node *pNext, const char &value) :
        pNext_(pNext),
        data_(value) {


}

bool Stack::isEmpty() const {
    return (pHead_ == nullptr);
}


void Stack::pop() {
    if (!isEmpty()) {
        Node *pDeleted(pHead_);
        pHead_ = pDeleted->pNext_;
        delete pDeleted;
    }
}

void Stack::push(const char &value) {
    pHead_ = new Node(pHead_, value);
}

char &Stack::top() {
    if (isEmpty()) {
        throw invalid_argument("Hey, you! There is no TOP here :(");
    }
    return pHead_->data_;
}

const char &Stack::top() const {
    if (isEmpty()) {
        throw invalid_argument("Hey, you! There is no TOP here :(");
    }
    return pHead_->data_;
}

ostream &Stack::writeTo(ostream &ostrm) const {
    if (!isEmpty()) {
        Stack stack(*this);
        while (!stack.isEmpty()) {
            ostrm << stack.top() << endl;
            stack.pop();
        }
    }
    return ostrm;
}

ostream &operator<<(ostream &ostrm, const Stack &stack) {
    return stack.writeTo(ostrm);
}
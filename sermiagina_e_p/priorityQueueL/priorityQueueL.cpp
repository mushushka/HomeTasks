//
// Created by Елена Сермягина on 22.11.2017.
//
#include "priorityQueueL.h"
#include <iostream>
#include <stdexcept>

using namespace std;

PriorityQueueL::~PriorityQueueL() {
    while (!isEmpty()) {
        pop();
    }
}

PriorityQueueL::Node::Node(Node *pNext) :
        pNext_(pNext),
        data_(double(0.0)) {

}

PriorityQueueL::Node::Node(Node *pNext, const double &value) :
        pNext_(pNext),
        data_(value) {


}

PriorityQueueL::PriorityQueueL(const PriorityQueueL &copyPriorityQueueL) {
    // PriorityQueueL queue;
    Node *pCopyFrom(copyPriorityQueueL.pHead_);
    // Node* pCopyTo(pHead_);
    while (pCopyFrom != nullptr) {

        push(pCopyFrom->data_);
        pCopyFrom = pCopyFrom->pNext_;
        // pCopyTo -> pNext_ = new Node(nullptr, pCopyFrom -> data_);

    }
}

PriorityQueueL &PriorityQueueL::operator=(const PriorityQueueL &copyPriorityQueueL) {
    Node *pCopyFrom(copyPriorityQueueL.pHead_);
    Node *pCopyTo(pHead_);

    while (pCopyFrom != copyPriorityQueueL.pTail_ && pCopyTo != pTail_) {

        pCopyTo->data_ = pCopyFrom->data_;
        pCopyFrom = pCopyFrom->pNext_;
        pCopyTo = pCopyTo->pNext_;
    }
    if (pCopyFrom == copyPriorityQueueL.pTail_ && pCopyTo != pTail_) {

        pCopyTo->data_ = pCopyFrom->data_;
        while (pCopyTo != nullptr) {
            Node *pDeleted(pCopyTo);
            pCopyTo = pDeleted->pNext_;
            delete pDeleted;

        }

    } else if (pCopyFrom != copyPriorityQueueL.pTail_ && pCopyTo == pTail_) {

        pCopyTo->data_ = pCopyFrom->data_;
        while (pCopyFrom != nullptr) {

            push(pCopyFrom->data_);
            pCopyFrom = pCopyFrom->pNext_;

        }
    }


    return *this;

}

void PriorityQueueL::push(const double &value) {
    Node *temp;
    if (isEmpty()) {
        pHead_ = new Node(nullptr, value);
        pTail_ = pHead_;
    } else {
        if (value - pHead_->data_ > e) {
            pHead_ = new Node(pHead_, value);

        } else {
            temp = pHead_;
            while (temp->pNext_ != nullptr && value - temp->pNext_->data_ <= e) {
                temp = temp->pNext_;
            }
            Node *newNode = temp->pNext_;
            temp->pNext_ = new Node(newNode, value);

        }

    }

}

void PriorityQueueL::pop() {
    if (isEmpty()) {
        throw invalid_argument("Hey, you! It's empty! :(");
    }
    Node *pDeleted(pHead_);
    pHead_ = pDeleted->pNext_;
    delete pDeleted;


}

bool PriorityQueueL::isEmpty() const {
    return (pHead_ == nullptr);
}

double &PriorityQueueL::last() {
    return pTail_->data_;
}

const double &PriorityQueueL::last() const {
    return pTail_->data_;
}

const double &PriorityQueueL::first() const {
    return pHead_->data_;
}

double &PriorityQueueL::first() {
    return pHead_->data_;
}

std::ostream &PriorityQueueL::writeTo(std::ostream &ostrm) const {
    if (!isEmpty()) {
        PriorityQueueL tempQueue(*this);
        while (!tempQueue.isEmpty()) {
            ostrm << tempQueue.first() << endl;
            tempQueue.pop();
        }

    }

    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, const PriorityQueueL &queue) {
    return queue.writeTo(ostrm);
}
//
// Created by Елена Сермягина on 22.11.2017.
//
#include "priorityQueueL.h"
#include <iostream>

using namespace std;

PriorityQueueL::~PriorityQueueL() {
    clear();
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
    copy(copyPriorityQueueL);
}

PriorityQueueL &PriorityQueueL::operator=(const PriorityQueueL &copyPriorityQueueL) {
    if (copyPriorityQueueL.isEmpty()) {
        this->clear();
    }
    if (this->isEmpty()) {
        this->copy(copyPriorityQueueL);
    }

    Node *pCopyFrom(copyPriorityQueueL.pHead_);
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


//    if (!this->isEmpty() && !copyPriorityQueueL.isEmpty()) {
//        Node *pCopyFrom(copyPriorityQueueL.pHead_);
//        Node *pCopyTo(pHead_);
//        pCopyTo->data_ = pCopyFrom->data_;
//
//        while (pCopyFrom->pNext_ != nullptr && pCopyTo->pNext_ != nullptr) {
//            pCopyFrom = pCopyFrom->pNext_;
//            pCopyTo = pCopyTo->pNext_;
//            pCopyTo->data_ = pCopyFrom->data_;
//        }
//
//        if (pCopyTo->pNext_ == nullptr) {
//            while (pCopyFrom->pNext_ != nullptr) {
//                pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->pNext_->data_);
//                pCopyTo = pCopyTo->pNext_;
//                pCopyFrom = pCopyFrom->pNext_;
//
//            }
//        }
//
//        if (pCopyFrom == nullptr) {
//           // pCopyTo->data_ = pCopyFrom->data_;
//            while (pCopyTo != nullptr) {
//                Node *pDelete(pCopyTo);
//                pCopyTo = pDelete->pNext_;
//               // temp = pCopyTo;
//                delete pDelete;
//
//
//            }
//        }
//    }

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
    error();
    Node *pDeleted(pHead_);
    pHead_ = pDeleted->pNext_;
    delete pDeleted;


}

bool PriorityQueueL::isEmpty() const {
    return (pHead_ == nullptr);
}


const double &PriorityQueueL::first() const {
    error();
    return pHead_->data_;
}

double &PriorityQueueL::first() {
    error();
    return pHead_->data_;
}

void PriorityQueueL::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void PriorityQueueL::error() const {
    if (isEmpty()) {
        throw invalid_argument("Hey, you! It's empty! :(");
    }
}

void PriorityQueueL::copy(const PriorityQueueL &copyPriorityQueueL) {
    Node *pCopyFrom(copyPriorityQueueL.pHead_);
    while (pCopyFrom != nullptr) {
        push(pCopyFrom->data_);
        pCopyFrom = pCopyFrom->pNext_;
    }
}

std::ostream &PriorityQueueL::writeTo(std::ostream &ostrm) const {
    if (!isEmpty()) {
        PriorityQueueL tempQueue(*this);
        while (!tempQueue.isEmpty()) {
            ostrm << tempQueue.first() << endl;
            tempQueue.pop();
        }

    } else {
        ostrm << "Queue is empty!" << endl;
    }

    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, const PriorityQueueL &queue) {
    return queue.writeTo(ostrm);
}
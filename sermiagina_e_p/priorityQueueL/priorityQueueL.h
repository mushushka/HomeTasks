//
// Created by Елена Сермягина on 22.11.2017.
//

#ifndef PRIORITYQUEUEL_PRIORITYQUEUEL_H
#define PRIORITYQUEUEL_PRIORITYQUEUEL_H
#include <iosfwd>

class PriorityQueueL {

public:
    PriorityQueueL() = default;
    ~PriorityQueueL();

    PriorityQueueL(const PriorityQueueL& copyPriorityQueueL);
    PriorityQueueL& operator=(const PriorityQueueL& copyPriorityQueueL);
    void push(const double& value);
    void pop();
    double& last();
    const double& last() const;
    const double& first() const;
    double& first();
    bool isEmpty() const;
    std::ostream& writeTo(std::ostream& ostrm) const;


private:
    double e = 10E-6;
    struct Node {
        Node(Node* pNext);
        Node(Node* pNext, const double& value);
        Node* pNext_{nullptr};
        double data_{double(0.0)};
    };
    Node* pHead_{nullptr};
    Node* pTail_{nullptr};

};

std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& queue);
#endif //PRIORITYQUEUEL_PRIORITYQUEUEL_H

//
// Created by Елена Сермягина on 25.11.2017.
//

#include "priorityQueueL.h"
#include <iostream>

using namespace std;

int main() {
PriorityQueueL que;
    que.push(11.3);
    que.push(11.4);
    que.push(2.2);
    que.push(10.3);
    que.push(34.4);
    que.push(72.2);
    cout<< endl << que  << endl;
    que.pop();
    cout << que  << endl;
    que.push(100.1);
    cout << que  << endl;

    PriorityQueueL que1(que);
    cout <<"copy :" << endl <<que1 << endl;

    PriorityQueueL que2;
    que2.push(341.3);
    que2.push(1341.4);
    que2.push(342.2);
    que2.push(3410.3);
    que2.push(334.4);
    que2.push(372.2);

    cout <<"2:" << endl <<que2 << endl;

    que2 = que1;
    cout <<"new:" << endl <<que2 << endl;

    que2.pop();
    cout <<"pop que2:" << endl <<que2 << endl;
    que2 = que1;
    cout <<"que2 = que1:" << endl <<que2 << endl;


    return 0;
}
//
// Created by Елена Сермягина on 25.11.2017.
//

#include "priorityqueuel.h"
#include <iostream>

using namespace std;

int main() {

    cout << endl << "Hello, queues!" << endl;

    cout << endl << "Welcome our first que:" << endl;
    PriorityQueueL que;
    que.push(11.3);
    que.push(12.4);
    que.push(2.2);
    cout << que << endl;

    cout << endl << "And now welcome our second que:" << endl;
    PriorityQueueL que2;
    que2.push(341.3);
    que2.push(1341.4);
    que2.push(342.2);
    cout << que2 << endl;

    cout << endl << "Each of them has 3 numbers. Let's pop one number from the first one and push to the second one."
         << endl;
    que.pop();
    que2.push(100500);
    cout << "The first" << endl << que << endl;
    cout << "The second" << endl << que2 << endl;

    cout << endl << "Our queues are bored and they need some friends. Welcome two empty queues three and four." << endl;
    PriorityQueueL que3;
    PriorityQueueL que4;
    cout << "The third" << endl << que3 << endl;
    cout << "The fourth" << endl << que4 << endl;

    cout << endl << "Let's give some numbers to empty queues." << endl;
    que3.push(100.3);
    que3.push(200.4);
    que3.push(300.2);
    que3.push(400.3);
    que3.push(500.4);
    que3.push(600.2);

    que4.push(10.3);
    que4.push(20.4);
    que4.push(30.2);
    que4.push(40.3);
    que4.push(50.4);
    que4.push(60.2);
    que4.push(70.7);

    cout << "The third" << endl << que3 << endl;
    cout << "The fourth" << endl << que4 << endl;

    cout << endl
         << "Okay, they are friends now. The first one will be with the third and the second one - with the fourth"
         << endl;
    que = que3;
    que4 = que2;
    cout << "The first" << endl << que << endl;
    cout << "The second" << endl << que2 << endl;
    cout << "The third" << endl << que3 << endl;
    cout << "The fourth" << endl << que4 << endl;

    cout << endl << "Do some bad things:" << endl;
    PriorityQueueL wowQueue;

    try {
        wowQueue.first();
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << endl << "Hey, is wowQue empty?:" << endl;
    cout << "wowQue: " << wowQueue;


    return 0;
}
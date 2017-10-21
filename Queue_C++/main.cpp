#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"
using namespace std;

int main(void) {
    MyQueue *p = new MyQueue(4);
    p->EnQueue(30);
    cout << endl;
    p->EnQueue(20);
    cout << endl;
    p->QueueTraverse();
    cout << endl;
    int e = 0;
    p->DeQueue(e);
    cout << endl;
    p->QueueTraverse();
    cout << endl;
    p->EnQueue(40);
    cout << endl;
    p->DeQueue(e);
    cout << endl;
    p->QueueTraverse();
    cout << endl;
    cout << p->QueueLength();
    cout << endl;
    p->EnQueue(12);
    cout << endl;
    p->EnQueue(13);
    cout << endl;
    p->EnQueue(14);
    cout << endl;
    p->EnQueue(14);
    cout << endl;
    p->EnQueue(14);
    cout << endl;
    p->QueueTraverse();
    cout << endl;
    cout << p->QueueLength();
    cout << endl;
    return 0;
}
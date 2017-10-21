//
// Created by wangxy on 10/21/17.
//

#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue
{
public:
    MyQueue(int queueCapacity);     //InitQueue(&Q)
    virtual ~MyQueue();             //DestroyQueue(&Q)
    void ClearQueue();              //ClearQueue(&Q)
    bool QueueEmpty() const;        //QueueEmpty(Q)
    bool QueueFull();
    int QueueLength() const;        //QueueLength(Q)
    bool EnQueue(int element);      //EnQueue(&Q, element)
    bool DeQueue(int &element);     //DeQueue(&Q, &element)
    void QueueTraverse();           //QueueTraverse(Q, visit())
private:
    int *m_pQueue;
    int m_iQueueLen;
    int m_iQueueCapacity;
    int m_Head;
    int m_Tail;
};


#endif //YQUEUE_H

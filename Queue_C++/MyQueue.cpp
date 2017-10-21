//
// Created by wangxy on 10/21/17.
//
#include "MyQueue.h"
#include <iostream>

using namespace std;

MyQueue::MyQueue(int queueCapacity) {
    m_iQueueCapacity = queueCapacity;
    ClearQueue();
    m_pQueue = new int[m_iQueueCapacity];
}

MyQueue::~MyQueue() {
    delete []m_pQueue;
    m_pQueue = NULL;
}

void MyQueue::ClearQueue() {
    m_Head = 0;
    m_Tail = 0;
    m_iQueueLen = 0;
}

bool MyQueue::QueueFull() {
    return m_iQueueLen == m_iQueueCapacity ? true : false;
}

int MyQueue::QueueLength() const {
    cout << "length:";
    return m_iQueueLen;
}

bool MyQueue::QueueEmpty() const {
    return m_iQueueLen == 0 ? true : false;
}

bool MyQueue::EnQueue(int element) {
    if (QueueFull()) {
        return false;
    }
    m_pQueue[m_Tail] = element;
    m_Tail++;
    m_Tail = m_Tail % m_iQueueCapacity;
    m_iQueueLen++;
    cout << "add:" << element;
}

bool MyQueue::DeQueue(int &element) {
    if (QueueEmpty()){
        return false;
    }
    element = m_pQueue[m_Head];
    m_Head++;
    m_Head = m_Head % m_iQueueCapacity;
    m_iQueueLen--;
    cout << "remove:" << element;
}

void MyQueue::QueueTraverse() {
    cout << "queue:" << endl;
    for (int i = m_Head; i < m_iQueueLen + m_Head ; ++i) {
        cout << m_pQueue[i % m_iQueueCapacity];
        cout << endl;
    }
}

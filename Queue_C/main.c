#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int *m_pQueue;
unsigned int m_QueueCapacity;
unsigned int m_Head;
unsigned int m_Tail;
unsigned int m_QueueLen;


void InitQueue(int m_queueCapacity){
    m_QueueCapacity = m_queueCapacity;
    m_pQueue = (int *)malloc(sizeof(int)*m_queueCapacity);
    ClearQueue();
}

void ClearQueue(){
    m_Head = 0;
    m_Tail = 0;
    m_QueueLen = 0;
}

bool QueueEmpty(){
    return 0 == QueueLength() ? true : false;
}

bool QueueFull(){
    return m_QueueCapacity == QueueLength() ? true : false;
}

int QueueLength(){
    printf("%s%d\n", "length:", m_QueueLen);
    return m_QueueLen;
}

bool EnQueue(int value){
    if (QueueFull()){
        printf("%s\n", "QueueFull");
        return false;
    }
    m_pQueue[m_Tail] = value;
    m_Tail++;
    m_Tail = m_Tail % m_QueueCapacity;
    m_QueueLen++;
    printf("%s%d\n", "add:", value);
}

bool DeQueue(){
    if (QueueEmpty()){
        printf("%s\n", "QueueEmpty");
        return false;
    }
    int temp = m_pQueue[m_Head];
    m_pQueue[m_Head] = NULL;
    m_Head++;
    m_Head = m_Head % m_QueueCapacity;
    m_QueueLen--;
    printf("%s%d\n", "remove:", temp);
}

void QueueTraverse(){
    printf("Queue:\n");
    for (int i = m_Head; i < m_QueueLen + m_Head; ++i) {
        printf("%d\n", m_pQueue[i % m_QueueCapacity]);
    }
}

int main() {
    InitQueue(4);
    EnQueue(4);
    EnQueue(5);
    EnQueue(6);
    EnQueue(7);
    EnQueue(8);
    QueueLength();
    QueueTraverse();
    DeQueue();
    QueueTraverse();
    QueueLength();
    EnQueue(9);
    QueueTraverse();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    QueueLength();
    DeQueue();
    return 0;
}
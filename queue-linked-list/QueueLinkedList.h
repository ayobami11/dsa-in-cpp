#pragma once

#include "LinkedList.h"

class QueueLinkedList : public LinkedList
{
public:
    QueueLinkedList();
    virtual ~QueueLinkedList();

    void enqueue(int);
    int dequeue();
    bool isEmpty();
};

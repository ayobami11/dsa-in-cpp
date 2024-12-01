#pragma once

#include "QueueLinkedList.h"

QueueLinkedList::QueueLinkedList() {}

QueueLinkedList::~QueueLinkedList() {}

void QueueLinkedList::enqueue(int value)
{
    appendNode(value);
}

int QueueLinkedList::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }

    int returnValue = head->data;
    Node *temp = head;

    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
    return returnValue;
}

bool QueueLinkedList::isEmpty()
{
    return head == NULL;
}

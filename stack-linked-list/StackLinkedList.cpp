#include "StackLinkedList.h"

StackLinkedList::StackLinkedList() {}

StackLinkedList::~StackLinkedList() {}

void StackLinkedList::push(int data)
{
    appendNode(data);
}

int StackLinkedList::pop()
{
    if (isEmpty())
    {
        return -1;
    }

    int returnValue = tail->data;
    Node *temp = tail;

    if (tail->prev == NULL)
    {
        // last element does not have a parent node; this implies it is the root node
        head = NULL;
        tail = NULL;
    }
    else
    {
        // we need to store another reference to the tail so we can access and delete it later
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
    return returnValue;
}

bool StackLinkedList::isEmpty()
{
    return head == NULL;
}
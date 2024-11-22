#pragma once

#include <iostream>

typedef struct Node
{

    struct Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    int data;
    struct Node *next;
    struct Node *prev;

} NODE;

class LinkedList
{
private:
    NODE *head;
    NODE *tail;

public:
    LinkedList(void);
    ~LinkedList(void);

    void appendNode(int);
    void displayNodes();
    void displayNodesReverse();
    void destroyList();
};

#pragma once

#include <iostream>

struct Node
{

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
protected:
    Node *head;
    Node *tail;

public:
    LinkedList(void);
    ~LinkedList(void);

    void appendNode(int);
    void displayNodes();
    void displayNodesReverse();
    void destroyList();
};

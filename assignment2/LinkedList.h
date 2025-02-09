#pragma once

#include <iostream>
#include "StdAfx.h"

using namespace System;

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

ref class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
    void removeNode(Node *);

public:
    LinkedList(void);
    ~LinkedList(void);

    void removeNodeAt(int);
    void deleteNode(int);
    int findNode(int);
    void insertNodeAt(int, int);
    int peek(int);
    int getSize();

    void appendNode(int);
    String ^ displayNodes();
    String ^ displayNodesReverse();
    void destroyList();
};

#pragma once

#include <iostream>

using namespace std;

struct Node
{

    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

    void removeNode(Node *);

public:
    LinkedList(void);
    ~LinkedList(void);

    void appendNode(int);
    void displayNodes();
    void displayNodesReverse();
    void deleteNodeByIndex(int);
    void deleteNodeByValue(int);
    // returns the value of a node provided its index
    int peek(int);
    // returns the index of a node provided its value
    int findNode(int);
    void insertAt(int, int);
    void insertAfter(int, int);
    void insertBefore(int, int);
    void destroyList();
};

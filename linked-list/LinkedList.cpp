#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList()
{
    destroyList();
}

void LinkedList::appendNode(int data)
{

    Node *newNode = new Node(data);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::displayNodes()
{

    Node *current = head;

    cout << "\nNodes:";

    while (current != NULL)
    {
        cout << " " << current->data;
        current = current->next;
    }
}

void LinkedList::displayNodesReverse()
{

    Node *current = tail;

    cout << "\nNodes in reverse order:";

    while (current != NULL)
    {
        cout << " " << current->data;
        current = current->prev;
    }
}

void LinkedList::destroyList()
{

    Node *current = tail;

    while (current != NULL)
    {
        Node *temp = current;
        current = current->prev;
        delete temp;
    }

    head = NULL;
    tail = NULL;
}
#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

LinkedList::~LinkedList()
{
    destroyList();
}

void LinkedList::removeNode(Node *node)
{

    if (node->prev == NULL && node->next == NULL)
    {
        // node to be removed is the only node in the linked list
        head = NULL;
        tail = NULL;
    }
    else if (node->prev == NULL)
    {
        // node to be removed is the first node in the linked list
        head = node->next;
        node->next->prev = NULL;
    }
    else if (node->next == NULL)
    {
        // node to be removed is the last node in the linked list
        tail = node->prev;
        node->prev->next = NULL;
    }
    else
    {
        // node to be removed is somewhere in the middle of the linked list
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    delete node;
    size--;
}

void LinkedList::removeNodeAt(int index)
{

    if (index < 0 || index >= size)
    {
        return;
    }

    Node *current = head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    removeNode(current);
}

void LinkedList::deleteNode(int data)
{

    Node *current = head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            removeNode(current);
            return;
        }

        current = current->next;
    }
}

int LinkedList::findNode(int data)
{

    Node *current = head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

void LinkedList::insertNodeAt(int index, int data)
{

    if (index < 0 || index > size)
    {
        return;
    }

    Node *newNode = new Node(data);

    if (size == 0)
    {
        // the linked list is empty
        head = newNode;
        tail = newNode;
    }
    else if (index == 0)
    {
        // new node is to be inserted at the head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (index == size)
    {
        // new node is to be inserted at the tail
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        // new node is to be inserted somewhere in the middle of the list
        Node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    size++;
}

int LinkedList::peek(int index)
{

    if (index < 0 || index >= size)
    {
        return 0;
    }

    Node *current = head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

int LinkedList::getSize()
{
    return size;
}

// insert a new node after a specified Node with data of value
void LinkedList::insertAfter(int value, int data)
{

    Node *current = head;

    while (current != NULL)
    {

        if (current->data == value)
        {
            Node *newNode = new Node(data);

            if (current == tail)
            {
                appendNode(data);
            }
            else
            {
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
                newNode->prev = current;

                size++;
            }

            return;
        }

        current = current->next;
    }

    // if we reach this point, the value provided to insert a new node after was not found
    cerr << "\nValue " << value << " was not found.";
}

// Appends a node to the end (tail) of the linked list.
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

    size++;
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
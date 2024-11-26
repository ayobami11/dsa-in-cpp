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

// Inserts a new node at position n; n is zero-indexed with 0 representing the head of the list.
void LinkedList::insertAt(int index, int data)
{

    if (index < 0)
    {
        cerr << "\nPlease provide a positive integer as an index.";
    }

    Node *newNode = new Node(data);

    // insert at the head
    if (index == 0)
    {

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;

            head = newNode;
        }

        return;
    }

    // insert somewhere in the middle of the list
    Node *current = head;
    int count = 0;

    while (current != NULL)
    {

        if (count == index)
        {
            newNode->next = current;
            current->prev->next = newNode;
            newNode->prev = current->prev;
            current->prev = newNode;
            return;
        }

        current = current->next;
        count++;
    }

    // if we get to this point, we are at the tail of the list, so we insert at the tail if the index of incoming node matches the count.
    if (index == count)
    {
        append(data);
    }
    else
    {
        cerr << "\nIndex is out of range.";
        delete newNode;
    }
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
                append(data);
            }
            else
            {
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
                newNode->prev = current;
            }

            return;
        }

        current = current->next;
    }

    // if we reach this point, the value provided to insert a new node after was not found
    cerr << "\nValue " << value << " was not found.";
}

void LinkedList::deleteNode(int value)
{

    if (head == NULL)
        return;

    Node *current = head;

    // node to delete is at the head
    if (current->data == value)
    {
        head = current->next;

        if (head == NULL)
        {
            // if the node to be deleted is the only node in the list
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }

        // delete the old head
        delete current;

        return;
    }

    while (current != NULL)
    {

        if (current->data == value)
        {

            current->prev->next = current->next;

            if (current == tail)
            {
                // node to delete is at the tail
                tail = current->prev;
            }
            else
            {
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }

        current = current->next;
    }
}

// Appends a node to the end (tail) of the linked list.
void LinkedList::append(int data)
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
#include "LinkedList.h"

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

    cout << "\nNodes: ";

    while (current != NULL)
    {
        cout << current->data << " ";

        current = current->next;
    }

    cout << endl;
}

void LinkedList::displayNodesReverse()
{

    Node *current = tail;

    cout << "\nNodes in reverse order: ";

    while (current != NULL)
    {
        cout << current->data << " ";

        current = current->prev;
    }

    cout << endl;
}

void LinkedList::deleteNodeByIndex(int index)
{

    if (index >= 0 && index < size && tail != NULL)
    {

        Node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        removeNode(current);
    }
}

void LinkedList::deleteNodeByValue(int value)
{

    if (tail != NULL)
    {

        Node *current = head;

        while (current != NULL)
        {

            if (current->data == value)
            {
                removeNode(current);
                break;
            }

            current = current->next;
        }
    }
}

void LinkedList::removeNode(Node *node)
{

    if (node->prev == NULL && node->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else if (node->prev == NULL)
    {
        node->next->prev = NULL;
        head = node->next;
    }
    else if (node->next == NULL)
    {
        node->prev->next = NULL;
        tail = node->prev;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    delete node;
    size--;
}

int LinkedList::peek(int index)
{

    if (index >= 0 && index < size && tail != NULL)
    {

        Node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    return -1;
}

int LinkedList::findNode(int value)
{

    if (tail != NULL)
    {

        Node *current = head;
        int index = 0;

        while (current != NULL)
        {

            if (current->data == value)
            {
                return index;
                break;
            }

            current = current->next;
            index++;
        }
    }

    return -1;
}

void LinkedList::insertAt(int index, int value)
{

    if (index >= 0 && index <= size)
    {

        Node *newNode = new Node(value);

        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else if (index == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (index == size)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {

            Node *current = head;

            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }

        size++;
    }
}

void LinkedList::insertAfter(int value, int newValue)
{

    Node *current = head;
    int count = 0;

    while (current != NULL)
    {

        if (current->data == value)
        {
            insertAt(count + 1, newValue);
            break;
        }

        current = current->next;
        count++;
    }
}

void LinkedList::insertBefore(int value, int newValue)
{

    Node *current = head;
    int count = 0;

    while (current != NULL)
    {

        if (current->data == value)
        {
            insertAt(count, newValue);
            break;
        }

        current = current->next;
        count++;
    }
}

void LinkedList::destroyList()
{

    Node *current = head;

    while (current != NULL)
    {
        Node *next = current->next;

        delete current;

        current = next;
    }

    head = NULL;
    tail = NULL;
}
#include <iostream>
#include <iomanip>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(void)
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList(void)
{
    destroyList();
}

void LinkedList::appendNode(string customerName, string customerPhoneNo, string productName, float productUnitPrice, int productQuantity)
{

    Node *newNode = new Node(customerName, customerPhoneNo, productName, productUnitPrice, productQuantity);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::displayNodes()
{

    // represents the current node (or customer) in the loop
    Node *current = head;

    while (current != NULL)
    {

        cout << "******************************************************" << endl;
        cout << setw(32) << "Yem Yem Ltd" << endl;
        cout << setw(40) << "University of Lagos, Akoka\n"
             << endl;

        cout << "Customer" << setw(21) << current->customerName << endl;
        cout << "Phone number" << setw(13) << current->customerPhoneNo << endl;

        cout << "\nYour Order" << endl;
        cout << "Product Name" << setw(13) << "UnitPrice" << setw(20) << "Quantity Ordered" << endl;
        cout << current->productName << setw(10) << current->productUnitPrice << setw(11) << current->productQuantity << endl;
        cout << setw(27) << "***********" << endl;
        cout << setw(27) << "Total Price" << setw(6) << current->totalPrice << endl;
        cout << setw(27) << "***********" << endl;

        cout << "\tThanks for your patronage" << endl;
        cout << "******************************************************\n"
             << endl;

        // move over to the next node
        current = current->next;
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

    // reset head and tail to their default values
    head = NULL;
    tail = NULL;
}

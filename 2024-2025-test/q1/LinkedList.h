#pragma once

#include <string>

using namespace std;

struct Node
{

    // data associated with the current node
    string customerName;
    string customerPhoneNo;
    string productName;
    float productUnitPrice;
    int productQuantity;
    float totalPrice;

    // previous node
    Node *prev;
    // next node
    Node *next;

    Node(string customerName, string customerPhoneNo, string productName, float productUnitPrice, int productQuantity)
    {
        this->customerName = customerName;
        this->customerPhoneNo = customerPhoneNo;
        this->productName = productName;
        this->productUnitPrice = productUnitPrice;
        this->productQuantity = productQuantity;
        this->totalPrice = productUnitPrice * productQuantity;

        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(void);
    ~LinkedList(void);

    void appendNode(string customerName, string customerPhoneNo, string productName, float productUnitPrice, int productQuantity);
    void displayNodes();
    void destroyList();
};

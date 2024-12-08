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

	void insertAfter(int, int);
	void appendNode(int);
	void displayNodes();
	void displayNodesReverse();
	void destroyList();
};

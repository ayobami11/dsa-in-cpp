#pragma once

#include <iostream>

struct Node {

	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}

	int data;
	Node* next;
	Node* prev;
};


class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList(void);
	~LinkedList(void);

	void insertAt(int, int);
	void insertAfter(int, int);
	void deleteNode(int);
	void append(int);
	void displayNodes();
	void displayNodesReverse();
	void destroyList();
};


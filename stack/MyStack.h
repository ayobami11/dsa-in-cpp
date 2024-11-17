#pragma once

#define DEFAULT_SIZE 10

class MyStack
{
private:
	int size;
	int top;
	int* values;

public:
	MyStack(int size = DEFAULT_SIZE);
	virtual ~MyStack();

	bool isEmpty();
	bool isFull();

	void push(int);
	int pop();
	int peek();
};


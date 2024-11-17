#pragma once

#include "MyStack.h"


MyStack::MyStack(int size)
{
	this->size = size;
	top = -1;
	values = new int[size];
}

MyStack::~MyStack(void)
{
	delete[] values;
	values = nullptr;
}

bool MyStack::isEmpty() {
	if (top == -1) {
		return true;
	} else {
		return false;
	}
}

bool MyStack::isFull() {
	if (top < size - 1) {
		return false;
	} else {
		return true;
	}
}

void MyStack::push(int value) {
	if (!isFull()) {
		top++;
		values[top] = value;
	}
}

int MyStack::pop() {

	if (!isEmpty()) {
		int poppedValue = values[top];
		top--;
		
		return poppedValue;
	}
	// default value to return if stack is empty
	return 0;
}

int MyStack::peek() {

	if (!isEmpty()) {
		return values[top];
	}

	// default value to return if stack is empty
	return 0;
}
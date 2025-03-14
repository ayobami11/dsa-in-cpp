#include "MyStack.h"

MyStack::MyStack(int size)
{
    top = -1;
    this->size = size;
    values = new char[size];
}

MyStack::~MyStack(void)
{
    delete[] values;
}

bool MyStack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyStack::isFull()
{
    if (top < size - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void MyStack::push(char character)
{

    if (!isFull())
    {
        top++;
        values[top] = character;
    }
}

char MyStack::pop()
{

    if (!isEmpty())
    {
        int poppedValue = values[top];
        top--;
        return poppedValue;
    }

    // default value to be returned if the stack is empty
    return '0';
}
#include "MyQueue.h"

MyQueue::MyQueue(int size)
{
    front = 0;
    back = 0;
    this->size = size;
    values = new int[size];
}

MyQueue::~MyQueue()
{
    delete[] values;
    values = nullptr;
}

bool MyQueue::isEmpty()
{
    if (front == back)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyQueue::isFull()
{
    if ((back + 1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyQueue::enqueue(int value)
{
    if (!isFull())
    {
        back = (back + 1) % size;
        values[back] = value;
    }
}

int MyQueue::dequeue()
{
    if (!isEmpty())
    {
        front = (front + 1) % size;
        return values[front];
    }
    // default value to return if queue is empty
    return 0;
}
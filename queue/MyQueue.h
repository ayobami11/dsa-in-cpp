#pragma once

#define DEFAULT_SIZE 10

class MyQueue
{
private:
    int front;
    int back;
    int size;
    int *values;

public:
    MyQueue(int size = DEFAULT_SIZE);
    virtual ~MyQueue();

    bool isEmpty();
    bool isFull();

    void enqueue(int);
    int dequeue();
};

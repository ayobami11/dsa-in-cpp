#pragma once
class MyStack
{
private:
    int *values;
    int size;
    int maxSize;

public:
    MyStack(int max_size);
    ~MyStack();

    bool isEmpty();
    bool isFull();

    void push(int value);
    int pop();
    int peek();

    int getSize();
    void print();
};

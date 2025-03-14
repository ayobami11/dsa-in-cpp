#pragma once

#define DEFAULT_SIZE 20

class MyStack
{
private:
    int size;
    int top;
    char *values;

public:
    MyStack(int size = DEFAULT_SIZE);
    ~MyStack(void);

    bool isEmpty();
    bool isFull();

    void push(char);
    char pop();
};

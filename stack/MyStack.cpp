#include <iostream>
#include "MyStack.h"

using namespace std;

// constructor
MyStack::MyStack(int max_size)
{
    values = new int[max_size]; // this is a pointer variable; check the header file
    size = 0;
    maxSize = max_size;

    /*
        My approach is a bit different from what was done in class:
        - size: number of elements currently in the stack; also serves as index of the next available position
            unlike top (from class) which represents the index of the last element in the stack i.e. size = top + 1

        - maxSize: maximum number of elements that the stack can contain
        - values: the array that would store the elements in the stack
            for this, we need to allocate memory dynamically. why? https://stackoverflow.com/questions/28625465/c-creating-an-array-with-a-size-entered-by-the-user how? https://www.programiz.com/cpp-programming/memory-management
    */
}

// destructor
MyStack::~MyStack()
{
    delete[] values;
    values = nullptr;
}

bool MyStack::isEmpty()
{
    return size == 0;
}

bool MyStack::isFull()
{
    return size >= maxSize;
}

void MyStack::push(int value)
{

    if (isFull())
    {
        cerr << "\nStack is already full.";
    }
    else
    {

        values[size] = value;
        size++;
    }
}

int MyStack::pop()
{

    if (isEmpty())
    {
        cerr << "\nStack is already empty.";
    }
    else
    {

        int top = values[size - 1];
        size--;

        return top;
    }
}

int MyStack::peek()
{

    if (isEmpty())
    {
        cerr << "\nStack is empty. Nothing to peek.";
    }
    else
    {
        // since size contains the index of the next available (empty) position; to get the actual last element, we do size - 1
        return values[size - 1];
    }
}

int MyStack::getSize()
{
    return size;
}

void MyStack::print()
{

    cout << "\n[";

    for (int i = 0; i < size; i++)
    {
        cout << values[i] << ((i < size - 1) ? ", " : "");
        // shorthand for if-else operation (ternary operator); we just want to check if we need to include a comma or not.
    }

    cout << "]" << endl;
}
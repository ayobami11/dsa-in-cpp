#include <iostream>

#include "MyStack.h"

using namespace std;

int main()
{

    MyStack *stack = new MyStack(20);

    stack->push('a');
    stack->push('b');
    stack->push('c');
    stack->push('d');

    cout << "\nOriginal string: abcd" << endl;

    cout << "Reversed string: ";
    for (int i = 0; i < 4; i++)
    {
        cout << stack->pop();
    }

    cout << endl;

    system("pause");

    return 0;
}
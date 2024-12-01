#include <iostream>

#include "StackLinkedList.h"

using namespace std;

int main()
{

    StackLinkedList *stack = new StackLinkedList();

    stack->push(10);
    stack->push(20);
    stack->push(30);

    stack->displayNodes();
    stack->displayNodesReverse();

    cout << "\n"
         << stack->pop() << endl;
    delete stack;

    cout << endl;

    system("pause");

    return 0;
}
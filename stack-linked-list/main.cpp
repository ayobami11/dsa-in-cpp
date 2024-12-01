#include <iostream>

#include "StackLinkedList.h"

using namespace std;

int main()
{

    StackLinkedList *stack = new StackLinkedList();

    stack->appendNode(10);
    stack->appendNode(20);
    stack->appendNode(30);

    stack->displayNodes();
    stack->displayNodesReverse();

    cout << "\n"
         << stack->pop() << endl;
    delete stack;

    cout << endl;

    system("pause");

    return 0;
}
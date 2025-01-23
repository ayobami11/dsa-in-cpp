#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *list = new LinkedList();

    list->insertAt(0, 20);
    list->insertAt(0, 25);
    list->insertAt(2, 55);
    list->insertAt(1, 35);
    list->insertAfter(35, 30);
    list->insertAfter(55, 100);
    list->insertBefore(55, 45);
    list->insertBefore(25, 5);

    // list->destroyList();

    list->displayNodes();
    list->displayNodesReverse();

    system("pause");

    return 0;
}
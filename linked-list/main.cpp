#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *list = new LinkedList();

    list->append(10);
    list->append(20);
    list->append(30);

    list->insertAt(0, 5);
    list->insertAfter(20, 25);

    list->append(400);
    list->deleteNode(400);

    list->displayNodes();
    list->displayNodesReverse();

    cout << endl;

    system("pause");

    return 0;
}
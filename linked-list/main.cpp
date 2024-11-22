#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *list = new LinkedList();

    list->appendNode(10);
    list->appendNode(20);
    list->appendNode(30);

    list->displayNodes();
    list->displayNodesReverse();

    cout << endl;

    system("pause");

    return 0;
}
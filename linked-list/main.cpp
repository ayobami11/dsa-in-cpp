#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

	LinkedList* list = new LinkedList();

	list->appendNode(10);
	list->appendNode(20);
	list->appendNode(30);
	list->appendNode(40);
	list->appendNode(50);

	list->insertNodeAt(0, 5);
	list->insertAfter(20, 25);

	list->appendNode(400);
	list->deleteNode(400);

	list->displayNodes();
	list->displayNodesReverse();

	cout << endl;

	system("pause");

	return 0;
}
#include <iostream>

#include "QueueLinkedList.h"

using namespace std;

int main()
{

    QueueLinkedList *queue = new QueueLinkedList();

    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);

    queue->displayNodes();
    queue->displayNodesReverse();

    cout << "\n"
         << queue->dequeue() << endl;
    delete queue;

    cout << endl;

    system("pause");

    return 0;
}
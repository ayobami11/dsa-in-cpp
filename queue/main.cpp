#include <iostream>

#include "MyQueue.h"

using namespace std;

int main()
{

    MyQueue *queue = new MyQueue(8);

    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);

    for (int i = 0; i < 3; i++)
    {
        cout << queue->dequeue() << endl;
    }

    cout << queue->dequeue() << endl;

    cout << endl;

    system("pause");

    return 0;
}
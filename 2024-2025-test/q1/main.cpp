#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *list = new LinkedList();
    list->appendNode("Adenola Adeniyi", "08062701569", "Chocolate", 500, 2);
    list->appendNode("Bukola Adenola ", "08035114392", "Bournvita", 6200, 3);
    list->displayNodes();
    delete list;

    system("pause");
}
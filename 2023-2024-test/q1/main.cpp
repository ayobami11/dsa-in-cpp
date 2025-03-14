#include "LinkedList.h"

using namespace std;

int main()
{

    LinkedList *list = new LinkedList();
    list->appendNode("Adenola Adeniyi", "A12", "Lagos", "London", "A12", "12:30pm", "29-1-2024", "134566");
    list->appendNode("Bukola Adenola", "A13", "Abuja", "Paris", "B45", "13:30pm", "30-1-2024", "134577");
    list->displayNodes();
    delete list;

    system("pause");
}
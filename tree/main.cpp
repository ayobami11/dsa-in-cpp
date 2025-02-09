#include "BinarySearchTree.h"

int main()
{

    BinarySearchTree *tree = new BinarySearchTree();
    char key[SIZE_KEY];
    char value[SIZE_VALUE];

    cout << "Adding three keys and values into the tree." << endl;

    for (int i = 0; i < 3; i++)
    {

        if (i == 0)
        {
            strcpy(key, "345");
            strcpy(value, "Bob");
        }
        else if (i == 1)
        {
            strcpy(key, "123");
            strcpy(value, "Mary");
        }
        else if (i == 2)
        {
            strcpy(key, "999");
            strcpy(value, "Sue");
        }

        if (!tree->contains(key))
        {
            cout << "Adding node - key: " << key << " value: " << value << endl;
            tree->add(key, value);
        }
        else
        {
            cout << "Generated duplicate key: " << key << endl;
        }
    }

    cout << "\nIn order traversal of tree:" << endl;
    tree->displayInOrder();

    cout << "\nDepth of tree before removing nodes: " << tree->getDepth() << endl;
    cout << "\nSize of tree before removing nodes: " << tree->getSize() << endl;

    cout << "\nRetrieving one value from the tree:" << endl;

    if (tree->get("123", value))
    {
        cout << " Value: " << value << endl;
    }

    cout << "\nRemoving one node from the tree:" << endl;
    if (tree->contains("123"))
    {
        tree->remove("123");
    }

    cout << "\nIn order traversal of tree:" << endl;
    tree->displayInOrder();
    cout << "\nDepth of tree after removing nodes: " << tree->getDepth() << endl;
    cout << "\nSize of tree after removing nodes: " << tree->getSize() << endl;

    cout << "\nDestroying the tree:" << endl;
    delete tree;

    cout << endl;

    system("pause");

    return 0;
}
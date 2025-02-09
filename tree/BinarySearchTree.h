#pragma once

#define SIZE_KEY 32
#define SIZE_VALUE 256

#include <iostream>
#include <string>

using namespace std;

struct Metadata
{

    Metadata(char *key, char *value)
    {
        strcpy(this->key, key);
        strcpy(this->value, value);
        left = NULL;
        right = NULL;
    }

    char key[SIZE_KEY];
    char value[SIZE_VALUE];
    Metadata *left;
    Metadata *right;
};

class BinarySearchTree
{
private:
    Metadata *root;
    int size;

    bool addNode(Metadata **, Metadata *);
    bool removeNode(Metadata **, char *key);
    void removeRootNode(Metadata **);
    void moveLeftMostNode(Metadata **, Metadata *);
    void removeAllNodes(Metadata *);
    bool getNode(Metadata *, char *, char *);
    bool containsNode(Metadata *, char *);
    void processNodesInOrder(Metadata *);
    int getTreeDepth(Metadata *);

public:
    BinarySearchTree(void);
    ~BinarySearchTree(void);

    int getSize();
    bool add(char *, char *);
    bool remove(char *);
    void removeAll();
    bool get(char *, char *);
    bool contains(char *);
    void displayInOrder();
    int getDepth();
};

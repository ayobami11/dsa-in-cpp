#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(void)
{
    root = NULL;
    size = 0;
}

BinarySearchTree::~BinarySearchTree(void)
{
    removeAll();
}

int BinarySearchTree::getSize()
{
    return size;
}

bool BinarySearchTree::add(char *key, char *value)
{

    if (key == NULL || value == NULL || strlen(key) >= SIZE_KEY || strlen(value) >= SIZE_VALUE)
    {
        return false;
    }

    Metadata *newNode = new Metadata(key, value);
    addNode(&root, newNode);
}

bool BinarySearchTree::addNode(Metadata **currentNode, Metadata *newNode)
{

    if (*currentNode == NULL)
    {
        *currentNode = newNode;
        size++;
        return true;
    }
    else
    {
        if (strcmp(newNode->key, (*currentNode)->key) < 0)
        {
            return addNode(&((*currentNode)->left), newNode);
        }
        else if (strcmp(newNode->key, (*currentNode)->key) > 0)
        {
            return addNode(&((*currentNode)->right), newNode);
        }
        else
        {
            delete newNode;
            return false;
        }
    }
}

bool BinarySearchTree::remove(char *key)
{
    return removeNode(&root, key);
}

bool BinarySearchTree::removeNode(Metadata **currentNode, char *key)
{

    if (*currentNode == NULL)
    {
        return false;
    }
    else
    {

        if (strcmp((*currentNode)->key, key) < 0)
        {
            return removeNode(&((*currentNode)->left), key);
        }
        else if (strcmp((*currentNode)->key, key) > 0)
        {
            return removeNode(&((*currentNode)->right), key);
        }
        else
        {
            removeRootNode(currentNode);
            size--;
            return true;
        }
    }
}

void BinarySearchTree::removeRootNode(Metadata **root)
{

    Metadata *temp;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        delete (*root);
        *root = NULL;
    }
    else if ((*root)->right == NULL)
    {
        temp = *root;
        *root = (*root)->left;
        delete temp;
    }
    else if ((*root)->left == NULL)
    {
        temp = *root;
        *root = (*root)->right;
        delete temp;
    }
    else
    {
        moveLeftMostNode(&((*root)->right), *root);
    }
}

void BinarySearchTree::moveLeftMostNode(Metadata **node, Metadata *root)
{

    if (*node != NULL && (*node)->left == NULL)
    {
        Metadata *temp = *node;
        strcpy(root->key, (*node)->key);
        strcpy(root->value, (*node)->value);
        *node = (*node)->right;
        delete temp;
    }
    else
    {
        moveLeftMostNode(&((*node)->left), root);
    }
}

void BinarySearchTree::removeAllNodes(Metadata *node)
{

    if (node != NULL)
    {
        removeAllNodes(node->left);
        removeAllNodes(node->right);

        cout << "Removing node - key: " << node->key << "\t" << node->value << endl;
        delete node;
    }
};

void BinarySearchTree::removeAll()
{

    removeAllNodes(root);
    root = NULL;
    size = 0;
}

bool BinarySearchTree::get(char *key, char *value)
{
    return getNode(root, key, value);
}

bool BinarySearchTree::getNode(Metadata *node, char *key, char *value)
{

    if (node == NULL)
    {
        value[0] = '\0';
        return false;
    }
    else
    {

        if (strcmp(key, node->key) == 0)
        {
            strcpy(value, node->value);
            return true;
        }
        else if (strcmp(key, node->key) < 0)
        {
            return getNode(node->left, key, value);
        }
        else
        {
            return getNode(node->right, key, value);
        }
    }
}

bool BinarySearchTree::contains(char *key)
{
    return containsNode(root, key);
}

bool BinarySearchTree::containsNode(Metadata *node, char *key)
{

    if (node == NULL)
    {
        return false;
    }
    else
    {

        if (strcmp(key, node->key) == 0)
        {
            return true;
        }
        else if (strcmp(key, node->key) < 0)
        {
            return containsNode(node->left, key);
        }
        else
        {
            return containsNode(node->right, key);
        }
    }
}

void BinarySearchTree::displayInOrder()
{
    processNodesInOrder(root);
}

void BinarySearchTree::processNodesInOrder(Metadata *node)
{

    if (node != NULL)
    {
        processNodesInOrder(node->left);
        cout << "key: " << node->key << "\tvalue: " << node->value << endl;
        processNodesInOrder(node->right);
    }
}

int BinarySearchTree::getDepth()
{
    return getTreeDepth(root);
}

int BinarySearchTree::getTreeDepth(Metadata *node)
{

    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int depthLeft = getTreeDepth(node->left);
        int depthRight = getTreeDepth(node->right);

        if (depthLeft > depthRight)
        {
            return depthLeft + 1;
        }
        else
        {
            return depthRight + 1;
        }
    }
}
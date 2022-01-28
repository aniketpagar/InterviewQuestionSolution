/*
Binary Search Tree (BST).
Search particular node in the BST, if present return its address,
else return NULL.
*/

#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    struct BstNode *left;
    int data;
    struct BstNode *right;
};

typedef struct BstNode Node;
// create global root pointer
Node *root = NULL;


/*
API to create new node.
*/
Node *getNewNode(int value)
{
    // create new node.
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->left = NULL;
    newNode->data = value;
    newNode->right = NULL;

    return newNode;
}


/*
API to insert the nodes in order to create the BST.
Recursive Insert function is used.
Assumption: BST do not contain the duplicate values, so if value
is already present, it will not be added.
*/
Node *insert(Node *ptr, int value)
{
    // If BST is empty, create the new node and insert it as root node.
    if(ptr == NULL)
        ptr = getNewNode(value);
    // If nodes are present in the tree, then check for appropriate position to
    // enter the node.
    else if(value < ptr->data) // If duplicate is allowed else if(value <= ptr->data)
    {
        ptr->left = insert(ptr->left, value);
    }
    else
    {
        ptr->right = insert(ptr->right, value);
    }

    return ptr;
}


/*
API to display the tree in INORDER fashion.
*/
void printInorder(Node *ptr)
{
    // Tree is empty.
    if(ptr == NULL)
        return;

    printInorder(ptr->left);
    printf("%d -> ", ptr->data);
    printInorder(ptr->right);
}


/*
API to count the number of nodes in the tree.
*/
Node *search(Node *ptr, int key)
{
    if(ptr == NULL)
    {
        return NULL;
    }

    if(key == ptr->data)
        return ptr;
    else if(key < ptr->data)
        return search(ptr->left, key);
    else
        return search(ptr->right, key);
}


Node *searchIterative(Node *ptr, int key)
{
    while(ptr != NULL)
    {
        if(ptr->data == key)
            return ptr;
        else if(ptr->data < key)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }

    return NULL;
}


int main(void)
{
    root = insert(root, 30); // create the root node.
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);


    printInorder(root);
    printf("\n");

    int key = 10;
    Node *res = search(root, key);
    // Node *res = searchIterative(root, key);
    if(res != NULL)
        printf("FOUND");
    else
        printf("NOT FOUND");

    return 0;
}

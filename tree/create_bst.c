/*
Binary Search Tree (BST).
File contains the implementation of BST.
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
Iterative Method of inserting element in the array.
Idea is to check is value is already present. If yes, do not insert.
Otherwise insert at appropriate position.
*/
void insertIterative(Node *ptr, int value)
{
    // Tail pointer to keep track of root, when ptr becomes NULL.
    Node *tail = NULL;
    Node *newNode;

    // If tree is empty.
    if(ptr == NULL)
    {
        // Create new node and point root to that node.
        ptr = getNewNode(value);
        root = ptr;
        return;
    }

    // Firstly search if node with value is already present.
    while(ptr != NULL)
    {
        tail = ptr;

        if(value == ptr->data)
        {
            printf("Element is already present, will not insert\n");
            return;
        }
        else if(value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    // Node with value is not present, we can create new node and insert it.
    newNode = getNewNode(value);

    if(newNode->data < tail->data)
        tail->left = newNode;
    else
        tail->right = newNode;
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
API to display the tree in PREORDER fashion.
*/
void printPreorder(Node *ptr)
{
    // Tree is empty.
    if(ptr == NULL)
        return;

    printf("%d -> ", ptr->data);
    printPreorder(ptr->left);
    printPreorder(ptr->right);
}


/*
API to display the tree in POSTORDER fashion.
*/
void printPostorder(Node *ptr)
{
    // Tree is empty.
    if(ptr == NULL)
        return;

    printPostorder(ptr->left);
    printPostorder(ptr->right);
    printf("%d -> ", ptr->data);
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

    // insertIterative(root, 30);
    // insertIterative(root, 20);
    // insertIterative(root, 40);
    printInorder(root);
    printf("\n");
    printPreorder(root);
    printf("\n");
    printPostorder(root);

    return 0;
}

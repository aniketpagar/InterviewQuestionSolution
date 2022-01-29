/****************************************************************************
File name: height_bst.cpp

Author: babajr
*****************************************************************************/


/*
Binary Search Tree (BST).
Find the height of the tree.
            30
    20              40
10      25      35      50

Height = 2
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
API to find the height of the tree.
Idea is to get the height of left and right subtree.
height = max(h_leftSubtree, h_rightSubtree) + 1.

For empty tree, height is -1.
For one node heiht is 0.
*/
int height(Node *ptr)
{
    if(ptr == NULL)
        return -1;

    int x = height(ptr->left);
    int y = height(ptr->right);

    if(x > y)
        return x + 1;
    else
        return y + 1;
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

    printf("Height of BST: %d\n", height(root));

    return 0;
}

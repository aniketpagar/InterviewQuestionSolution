/****************************************************************************
File name: count_leaf_various_degree_nodes_bst.c

Author: babajr
*****************************************************************************/


/*
Binary Search Tree (BST).
Find the count of leaf nodes, degree(1) nodes, degree(2) nodes.
            30
    20              40
10      25      35      50

leaf nodes = 4
degree(1) nodes = 0
degree(2) nodes = 3
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
API to count leaf nodes. Leaf nodes are nodes whose left and right pointer
points to null.
if(ptr->left == NULL && ptr->right == NULL)
    print(LEAF NODE)
*/
int countLeafNodes(Node *ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left == NULL && ptr->right == NULL)
            return (countLeafNodes(ptr->left) +
                    countLeafNodes(ptr->right) + 1);
        else
            return (countLeafNodes(ptr->left) +
                    countLeafNodes(ptr->right));
    }

    return 0;
}


/*
API to count degree(1) nodes.
if(ptr->left != NULL ^ ptr->right != NULL)

*/
int countDegree1Nodes(Node *ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left != NULL ^ ptr->right != NULL)
            return (countDegree1Nodes(ptr->left) +
                    countDegree1Nodes(ptr->right) + 1);
        else
            return (countDegree1Nodes(ptr->left) +
                    countDegree1Nodes(ptr->right));
    }

    return 0;
}


/*
API to count degree(2) nodes.
if(ptr->left != NULL && ptr->right != NULL)
    print(LEAF NODE)
*/
int countDegree2Nodes(Node *ptr)
{
    if(ptr != NULL)
    {
        if(ptr->left != NULL && ptr->right != NULL)
            return (countDegree2Nodes(ptr->left) +
                    countDegree2Nodes(ptr->right) + 1);
        else
            return (countDegree2Nodes(ptr->left) +
                    countDegree2Nodes(ptr->right));
    }

    return 0;
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

    printf("Count of Leaf Nodes of BST: %d\n", countLeafNodes(root));
    printf("Count of Degree 1 Nodes of BST: %d\n", countDegree1Nodes(root));
    printf("Count of Degree 2 Nodes of BST: %d\n", countDegree2Nodes(root));

    return 0;
}

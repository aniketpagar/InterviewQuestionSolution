/*
Binary Search Tree (BST).
Delete the node if found in the BST. If node is not present, return NULL.
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


/*
API to get the Inorder Predecessor of node.
*/
Node *inorderPredecessor(Node *ptr)
{
    while(ptr != NULL && ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}


/*
API to get the Inorder Successor of node.
*/
Node *inorderSuccessor(Node *ptr)
{
    while(ptr != NULL && ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}


/*
API to delete the node in the bst.
Idea is to delete nodes directly if they are leaf nodes.
But special cases, like nodes other than the leaf nodes, replace those nodes
with Inorder Predecessor or Inorder Successor Nodes and delete them.

Inorder Predecessor: Right Most node in left subtree.

Inorder Successor: Left Most node in the right subtree.
*/
Node *delete(Node *ptr, int key)
{
    Node *q;
    if(ptr == NULL)
        return NULL;

    // leaf nodes.
    if(ptr->left == NULL && ptr->right == NULL)
    {
        //if only root node is present
        if(ptr == root)
            root = NULL;

        free(ptr);
        return NULL;
    }

    // search for the node with key value, if present delete it.
    if(key < ptr->data)
        ptr->left = delete(ptr->left, key);
    else if(key > ptr->data)
        ptr->right = delete(ptr->right, key);
    else // key is found. We can replace node with either Inorder Successor or
        // Inorder Predecessor and delete it. In this case, we will delete node
        // with larger height of subtree. i.e. left or right subtree.
    {
        if(height(ptr->left) > height(ptr->right)) // delete from left subtree
        {
            q = inorderPredecessor(ptr->left);
            // copy the data of predecessor node to ptr and delete the predecessor.
            ptr->data = q->data;
            ptr->left = delete(ptr->left, q->data);
        }
        else // delete from the right subtree.
        {
            q = inorderSuccessor(ptr->right);
            // copy the data of predecessor node to ptr and delete the predecessor.
            ptr->data = q->data;
            ptr->right = delete(ptr->right, q->data);
        }
    }

    return ptr;
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

    int key = 30;
    delete(root, key);

    printInorder(root);
    printf("\n");

    return 0;
}

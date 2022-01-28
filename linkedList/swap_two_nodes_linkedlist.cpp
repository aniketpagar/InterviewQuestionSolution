/*
Swap nodes in a linked list without swapping data.

Input : 10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head = NULL; // global head pointer

/*
API to display contents of the linkedlist using iterative approach.
*/
void display(Node *ptr)
{
    if(ptr == NULL)
    {
        printf("LINKED LIST is EMPTY\n");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}


/*
API to insert node always at the last position.
*/
void insertAtLast(Node *ptr, int value)
{
    Node *last = NULL; // pointer to point to last node of list.

    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // if list is empty i.e. head or ptr = NULL
    if(ptr == NULL)
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        last = ptr; // start last pointer from head
        while(last->next != NULL) // traverse the list until last pointer reach to last node of list.
        {
            last = last->next;
        }

        // create the link between last node to the new node and point
        // the last pointer to the new last node.
        last->next = newNode;
        last = newNode;
    }

}


/*
API to swap the given nodes of the linked list.

Probable Cases:
--> x and y may or may not be adjacent.
--> Either x or y may be a head node.
--> Either x or y may be the last node.
--> x and/or y may not be present in the linked list.
*/
void swap_nodes(Node *ptr, int x, int y)
{
    // pointers required to keep track of previous nodes of x and y to modify the links.
    Node *prev_x = NULL;
    Node *prev_y = NULL;
    Node *curr_x = ptr;
    Node *curr_y = ptr;

    // in case both values are same, no need to swap
    if(x == y)
        return;

    // search x and y in the linked list.
    while(curr_x != NULL && curr_x->data != x)
    {
        prev_x = curr_x;
        curr_x = curr_x->next;
    }

    while(curr_y != NULL && curr_y->data != y)
    {
        prev_y = curr_y;
        curr_y = curr_y->next;
    }

    // check if both the nodes are present in the list.
    // if both or either of the node is absent, we can not do the operation.
    if(curr_x == NULL || curr_y == NULL)
        return;

    // If x is not the head of list.
    // Make the link between prev_x to curr_y.
    if(prev_x != NULL)
        prev_x->next = curr_y;
    else // make curr_y as new head
        head = curr_y;

    // If y is not the head of list.
    // Make the linke between prev_y to curr_x.
    if(prev_y != NULL)
        prev_y->next = curr_x;
    else // make curr_x as new head
        head = curr_x;

    // swap the curr_x->next and curr_y->next
    Node *temp = curr_x->next;
    curr_x->next = curr_y->next;
    curr_y->next = temp;
}


int main(void)
{
    // always insert the node at 0th position first, otherwise
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);

    display(head);

    // swap_nodes(head, 10, 20); // case 1: x is head
    // swap_nodes(head, 20, 40); // case 2: x & y both are not head
    swap_nodes(head, 20, 50); // case 3: y is last node
    display(head);

    return 0;
}

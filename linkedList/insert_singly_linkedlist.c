/*
1. Insert new node of given value at given position in the Singly Linked List.
2. Insert new node at last position of the singly Linked List.
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
API to count number of nodes in the linked list.
*/
int count(Node *ptr)
{
    int nodeCount = 0;
    while(ptr != NULL)
    {
        nodeCount++;
        ptr = ptr->next;
    }

    return nodeCount;
}


/*
API to insert node at particular position.
*/
void insert(Node *ptr, int pos, int value)
{
    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // check for valid position
    if(pos < 0 || pos > count(ptr))
    {
        printf("Enter valid position. Either %d or less than %d\n", 0, count(ptr));
        return;
    }

    // inserting at the start of the list
    if(pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // make the ptr to point previous node of mentioned position.
        for(int i = 0; i < pos - 1; i++)
            ptr = ptr->next;

        // first make the link between new node to next node.
        // Then make link from previous node to new node.
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
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


/* Driver Code */
int main(void)
{
    insert(head, 0, 0);
    insert(head, 1, 1);
    insert(head, 2, 2);
    insert(head, 3, 3);
    insert(head, 3, 4);
    display(head);

    insertAtLast(head, 20);
    insertAtLast(head, 25);
    insertAtLast(head, 30);
    display(head);

    return 0;
}

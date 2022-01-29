/****************************************************************************
File name: pairwise_swap_linkedlist.cpp

Author: babajr
*****************************************************************************/


/*
Given a singly linked list, write a function to swap elements pairwise.

Input : 1->2->3->4->5->6->NULL
Output : 2->1->4->3->6->5->NULL

Input : 1->NULL
Output : 1->NULL
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
Helper API to swap the data of linked list nodes.
Doing call by address, as we want to swap the data of linked list in place.
*/
void swap(int *data1, int *data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}


/*
API to Pairwise swap elements of a given linked list.
*/
void swap_pairwise_nodes(Node *ptr)
{
    Node *temp = ptr;

    // traverse the list and swap the data of two nodes.
    // traverse ahead only if there are atleast 2 nodes.
    while(temp != NULL && temp->next != NULL)
    {
        // swap the data of curr node with the next node.
        swap(&temp->data, &temp->next->data);

        // update the temp pointer. skip the second element as it is already swapped.
        temp = temp->next->next;
    }
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

    swap_pairwise_nodes(head);
    display(head);

    return 0;
}


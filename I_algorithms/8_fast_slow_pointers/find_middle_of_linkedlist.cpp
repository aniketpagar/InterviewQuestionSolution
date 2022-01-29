/****************************************************************************
File name: find_middle_of_linkedlist.cpp

Author: babajr
*****************************************************************************/


/*
Given the head of a Singly LinkedList, write a method to return the middle node of the
LinkedList.

If the total number of nodes in the LinkedList is even, return the second middle node.
*/

#include<bits/stdc++.h>
using namespace std;


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
API to get the middle of the linked list.

Use Fast Slow Pointer Method.
Idea is to traverse the list with two pointers slow and fast.
slow will move one step at a time and fast will move two steps at a time.
When fast reaches to end, slow will be pointing to the middle of the list.
*/
Node *find_middle_linkedlist(Node *ptr)
{
    Node *slow = ptr;
    Node *fast = ptr;

    if(ptr == NULL)
    {
        printf("LIST is EMPTY\n");
        return NULL;
    }

    // two conditions are used for EVEN and ODD length Linked List.
    // ODD Lenghth = fast->next != NULL
    // EVEN Length = fast != NULL
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; // slow pointer moves one step at a time.
        fast = fast->next->next; // fast pointer moves two step at a time.
    }

    return slow;
}


int main(void)
{
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);
    insertAtLast(head, 60);

    display(head);

    printf("\n\n");

    Node *res = find_middle_linkedlist(head);

    if(res == NULL)
        printf("EMPTYYYYYYYYYY\n");
    else
        printf("Middle of Linked List : %d\n", *res);

    // printf("Middle of Linked List : %d\n", *find_middle_linkedlist(head));

    return 0;
}

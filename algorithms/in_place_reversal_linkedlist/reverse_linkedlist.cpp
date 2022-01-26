/*
Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to
return the new head of the reversed LinkedList.

Input: head ->  1   ->  2   ->  3   -> NULL
Output: NULL    <-  1   <-  2   <-  3   <-  head
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
In Place Reversal.

Algo:
--> reverse one node at a time.
--> start with a variable curr which will initially be curr = head and a variable
    prev which will point to the previous node that we have processed;
    initially prev = NULL.
--> In a stepwise manner, reverse the current node by pointing it to the
    previous node before moving on to the next node.
    Also, update the prev to always point to the previous node that
    we have processed.
*/
Node *reverse(Node *head)
{
    Node *curr = head; // current node that we will be processing.
    Node *prev = NULL; // previous node that is already processed.
    Node *next = NULL; // used to temporarily store next node.

    while(curr != NULL)
    {
        next = curr->next; // store the next node temporarily.
        curr->next = prev; // reverse the current node.
        prev = curr; // point prev to curr node before moving to the next node.
        curr = next; // move to the next node.
    }

    // at the end of the loop curr will be pointing to the NULL and
    // prev will be pointing to the last node.
    // prev will be our new head.
    return prev;
}


int main(void)
{
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    // insertAtLast(head, 80);

    printf("Original Linked List\n");
    display(head);

    printf("Reversed Linked List\n");
    head = reverse(head);
    display(head);

    return 0;
}

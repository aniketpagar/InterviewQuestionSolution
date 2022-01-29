/****************************************************************************
File name: find_cycle_length_in_linkedlist.cpp

Author: babajr
*****************************************************************************/


/*
Given the head of a LinkedList with a cycle, find the length of the cycle.
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
Helper API to get the length of the cycle in the linked list.
*/
int calculate_cycle_length(Node *slow)
{
    Node *current = slow;
    int cycle_length = 0;

    do
    {
        current = current->next;
        cycle_length++;
    } while(current != slow);

    return cycle_length;
}


/*
API to get the length of the cycle in the linked list.

Algo: As we get the cycle in the linked list. Save the slow pointer and use
      another pointer to traverse the list until it meets slow pointer again.

*/
int get_cycle_length(Node *ptr)
{
    Node *slow = ptr;
    Node *fast = ptr;

    while(fast != NULL && fast->next != NULL)
    {
        // move fast pointer by two and slow pointer by one in each iteration.
        fast = fast->next->next;
        slow = slow->next;

        // In case slow and faster pointers meets, then cycle is detected.
        // Calculate the length of the cycle.
        if(slow == fast)
        {
            return calculate_cycle_length(slow);
        }
    }

    // Loop is not found, return 0.
    return 0;
}


int main(void)
{
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 60);
    insertAtLast(head, 50);

    display(head);

    // create loop for testing
    Node *temp1, *temp2;
    temp1 = head->next->next;
    temp2 = head->next->next->next->next;
    temp2->next = temp1;

    printf("\n\n");

    printf("Linked List Cycle length: %d\n", get_cycle_length(head));

    return 0;
}

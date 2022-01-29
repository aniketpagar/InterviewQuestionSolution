/*
Given the head of a Singly LinkedList, write a function to determine if the LinkedList
has a cycle in it or not.
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
Fast and Slow Pointer method. TC = O(n)

Algo: Use two pointers to traverse the array. In each iteration fast pointer moves by 2
steps while slow pointer moves by one step.

--> While traversing the linked list if fast and slow pointers does not meet i.e.
    fast pointer reaches to the end of the list, that means there is no cycle in the
    linked list.
--> Other wise there is cycle in the list.
--> If list has a cycle, there can be 2 scenario possible.
    --> fast pointer is one step behind the slow pointer.
        == In this case for the next iteration, fast and slow will meet.
    --> fast pointer is two steps behind the slow pointer.
        == In this case, fast will be one step behind the slow poniter. That will
           be the above case.
*/
bool linkedlist_cycle(Node *ptr)
{
    Node *slow = ptr;
    Node *fast = ptr;

    while(fast != NULL && fast->next != NULL)
    {
        // move fast pointer by two steps and slow pointer by one step in each iteration.
        fast = fast->next->next;
        slow = slow->next;

        // In case two pointers meet, that means cycle is found
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}


/*
API to remove the loop in the linkedlist.
*/
void remove_loop(Node *ptr)
{
    Node *slow = ptr;
    Node *fast = ptr;

    while(fast != NULL && fast->next != NULL)
    {
        // move fast pointer by two steps and slow pointer by one step in each iteration.
        fast = fast->next->next;
        slow = slow->next;

        // In case two pointers meet, that means cycle is found
        if(slow == fast)
        {
            Node *temp1 = slow;
            Node *temp2 = ptr;

            while(temp1->next != temp2->next)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            temp1->next = NULL;
        }
    }
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
    // temp2->next = head;

    printf("\n\n");

    if(linkedlist_cycle(head) == 1)
        printf("Linked List contains LOOP\n");
    else
        printf("Linked List do NOT conatin LOOP\n");

    remove_loop(head);
    display(head);

    return 0;
}

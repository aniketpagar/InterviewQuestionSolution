/*
Given the head of a Singly LinkedList that contains a cycle, write a function to
find the starting node of the cycle.
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
Helper API to find the start of the cycle in the linked list.
*/
Node *find_start(Node *ptr, int cycle_length)
{
    // Using algo as mentioned in below API linked_list_start_of_cycle().
    Node *ptr1 = ptr;
    Node *ptr2 = ptr;

    // move ptr1 ahead of ptr2 by cycle_length nodes.
    while(cycle_length > 0)
    {
        ptr1 = ptr1->next;
        cycle_length--;
    }

    // increment both pointers until they meet at the start of the cycle.
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2; // ptr1
}


/*
API to get the start of the cycle in the linked list.

Algo:
--> Take two pointers i.e. ptr1 and ptr2.
--> Start both pointers from start of the linked list.
--> First find the length of the linked list cycle. Length of cycle = len.
--> Move ptr1 ahead of ptr2 by len nodes.
--> Keep incrementing ptr1 and ptr2 until they meet.
--> The meeting point of ptr1 and ptr2 will be start of the cycle.
*/
Node *linked_list_start_of_cycle(Node *ptr)
{
    int cycle_length = 0;

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
            cycle_length = calculate_cycle_length(slow);
            break;
        }
    }

    // Once the cycle length is calculated, find the start of the cycle.
    return find_start(head, cycle_length);
}


int main(void)
{
    // we will be creating list by inserting elements always at the end.
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

    printf("Linked List Start of the cycle: %d\n", *linked_list_start_of_cycle(head));

    return 0;
}

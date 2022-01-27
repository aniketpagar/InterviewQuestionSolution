/*
Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the
right by ‘k’ nodes.

Input: head ->  1   ->  2   ->  3   ->  4   ->  5   ->  6   ->  NULL, k = 3
Output: head -> 4   ->  5   ->  6   ->  1   ->  2   ->  3   ->  NULL
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

--> Take sublist of k ending nodes of the linked list and connect them to the start.
    While doing so, follow below 3 steps:
    --> Connect the last node of the LinkedList to the head.
    --> new head of linked list will be start node of the sublist.
    --> last node of linked list will be node before the start of the sublist.
*/
Node *rotate_list_with_k_size(Node *head, int k)
{
    // if list contains 0/1 nodes or number of rotation <= 0, no need to do anthing.
    if(head == NULL || head->next == NULL || k <= 0)
        return head;

    // get the length of the linked list as well as last node of the linked list.
    Node *last = head;
    int list_len = 1;

    while(last->next != NULL)
    {
        last = last->next;
        list_len++;
    }

    // 1. connect the last node to the start node of linked list
    last->next = head;

    // if k > size, no need to do rotations more than size of list
    k = k % list_len;
    int skip_len = list_len - k;
    Node *last_node_rotated_list = head;

    for(int i = 0; i < (skip_len - 1); i++) // we have to get to the node before start node of sublist
        last_node_rotated_list = last_node_rotated_list->next;

    // 2. Make head point to the start node of sublist.
    head = last_node_rotated_list->next;

    // 3. Make new last node of rotated list to point to NULL.
    last_node_rotated_list->next = NULL;

    // return the new head.
    return head;
}


int main(void)
{
    int k = 2; // size of the sub list.
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);
    insertAtLast(head, 60);
    insertAtLast(head, 70);
    insertAtLast(head, 80);

    printf("Original Linked List\n");
    display(head);

    printf("Reversed Linked List\n");
    head = rotate_list_with_k_size(head, k);
    display(head);

    return 0;
}

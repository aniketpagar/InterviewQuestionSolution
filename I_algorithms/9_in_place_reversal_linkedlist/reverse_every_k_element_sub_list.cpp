/****************************************************************************
File name: reverse_every_k_element_sub_list.cpp

Author: babajr
*****************************************************************************/


/*
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list
starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements,
reverse it too.

Input: head ->  1   ->  2   ->  3   ->  4   ->  5   ->  6   ->  NULL, k = 3
Output: head -> 3   ->  2   ->  1   ->  6   ->  5   ->  4   ->  NULL

Input: head ->  1   ->  2   ->  3   ->  4   ->  5   ->  6   ->  7   ->  8   ->  NULL, k = 3
Output: head -> 3   ->  2   ->  1   ->  6   ->  5   ->  4   ->  8   ->  7   ->  NULL
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

We can use same algorithm as mentioned in reverse_sub_list.cpp.

The only difference is that in this case we have to reverse all the sub lists.
Start with the first sublist (p = 1, q = k) and keep reversing all the sublists of size k.
*/
Node *reverse_every_k_elements(Node *head, int k)
{
    // if k = 1, means original list = reversed list, so no need to reverse.
    if(k <= 1 || head == NULL)
        return head;

    Node *curr = head;
    Node *prev = NULL;

    while(true)
    {
        Node *last_node_previous_part = prev;

        Node *last_node_sub_list = curr; // after reversing the sub list
                                         // curr will be the last node of sub list.
        Node *next = NULL; // use to temporarily store the next node while reversing the sublist.

        // reverse the sublist between p and q.
        for(int i = 0; curr != NULL && i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect reversed sublist with the first part.
        if(last_node_previous_part != NULL)
            last_node_previous_part->next = prev; // prev is now the first node of the sub list.
        else                                   // this means we are changing the first node (head) of linkedlist.
            head = prev;

        // connect reversed sublist with the next part.
        last_node_sub_list->next = curr;

        if(curr == NULL) // break the loop once we reached to end of the list.
            break;

        // prepare for the next sub list.
        prev = last_node_sub_list;
    }

    // return the new head.
    return head;
}


int main(void)
{
    int k = 5; // size of the sub list.
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
    head = reverse_every_k_elements(head, k);
    display(head);

    return 0;
}

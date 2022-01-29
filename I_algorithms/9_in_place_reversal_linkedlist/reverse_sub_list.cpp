/*
Given the head of a LinkedList and two positions ‘p’ and ‘q’,
reverse the LinkedList from position ‘p’ to ‘q’.

Input: head ->  1  ->  2  ->  3  ->  4   ->  5   ->  6  ->  NULL, p = 2, q = 4
Output: head ->  1  ->  4  ->  3  ->  2   ->  5   ->  6  ->  NULL
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

Ex:
head - 1 - 2 - 3 - 4 - 5 - 6 - NULL, p = 2, q = 4

--> firstly, skip the first p - 1 nodes to reach the position p.
    curr = p, prev = p - 1

    head - 1  -  2  -  3  -  4  -  5  -  6  -  NULL
        prev    curr

--> mark the node p-1 as last_node_first_part. i.e. last_node_first_part = prev.
    last_node_first_part will be used to connect with the reversed list.
    After reversal, curr will become the last node of sub list.
    i.e. last_node_sub_list = curr.

    head - 1  -  2  -  3  -  4  -  5  -  6  -  NULL
        prev    curr

   last_node_first_part = prev. (LNFP)
   last_node_sub_list = curr. (LNSL)

--> reverse the nodes from p to q.

    head - 1  <-  2  <-  3  <-  4    5  -  6  -  NULL
                               prev  curr

--> connect prev and q + 1 nodes to the reversed sublist.

    head - 1  <-  2  <-  3  <-  4    5  -  6  -  NULL
                               prev  curr
         LNFP    LNSL

    connect LNSL to start of last part i.e. curr.
    last_node_sub_list->next = curr.
    connect LNFP to end of first part i.e. prev.
    last_node_first_part->next = prev.

    head ->  1  ->  4  ->  3  ->  2   ->  5   ->  6  ->  NULL
*/
Node *reverse_sub_list(Node *head, int p, int q)
{
    // in case p and q are equal means size of sublist is 1 i.e. reversed sublist = original sublist.
    if(p == q)
        return head;

    // go to node p after skipping p-1 nodes.
    // at the end of loop curr will point to pth node
    // prev will point to p-1 node.
    Node *curr = head;
    Node *prev = NULL;
    for(int i = 0; curr != NULL && i < p - 1; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // Divide Linked List into 3 parts.
    // part 1: before p
    // part 2: between p and q
    // part 3: after q.
    Node *last_node_first_part = prev; // points to p-1

    Node *last_node_sub_list = curr; // after reversing the sub list
                                     // curr will be the last node of sub list.
    Node *next = NULL; // use to temporarily store the next node while reversing the sublist.

    // reverse the sublist between p and q.
    for(int i = 0; curr != NULL && i < (q-p+1); i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // connect reversed sublist with the first part.
    // two case: p > 1 and p = 1
    if(last_node_first_part != NULL) // p > 1
        last_node_first_part->next = prev;
    else // p = 1, change the first node i.e. head of linked list.
        head = prev;

    // connect reversed sublist with the last part.
    last_node_sub_list->next = curr;

    // return the new head.
    return head;
}


int main(void)
{
    int p = 2, q = 4; // start and end point of sub list
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 40);
    insertAtLast(head, 50);
    insertAtLast(head, 60);

    printf("Original Linked List\n");
    display(head);

    printf("Reversed Linked List\n");
    head = reverse_sub_list(head, p, q);
    display(head);

    return 0;
}

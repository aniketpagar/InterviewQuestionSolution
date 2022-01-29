/****************************************************************************
File name: delete_node_linkedlist_without_head.cpp

Author: babajr
*****************************************************************************/


/*
Delete a Node from linked list without head pointer.
No head reference is given to you. It is guaranteed that the
node to be deleted is not the last node.

Initial Linked List:
35 -> 15 -> 4 -> 20 -> NULL

Final Linked List after deletion of 15:
35 -> 4 -> 20 -> NULL
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
API to Delete a Node from linked list without head pointer.

NOTE: If node is last node we can not delete the node it is not posiible to delete
the node.

Algo:
--> Copy the data of the next node to the data field of the current node to be deleted.
--> Then move one step forward. Now next has become the current node and the current
    has become the previous node.
--> Delete the current node.

*/
void delete_node_without_header(Node *del)
{
    // Empty List.
    if(del == NULL)
        return;

    // last node can not be deleted with only pointer to the node to be deleted.
    if(del->next == NULL)
    {
        // printf("Last Node of the linked list can not be deleted this way\n");
        del = NULL;
        return;
    }

    Node *temp = del->next; // node to be deleted

    // copy the content of next node to the node to be deleted.
    del->data = del->next->data;

    // skip the next node as it it will be deleted.
    del->next = del->next->next;

    // delete the node
    free(temp);
}


int main(void)
{
    insertAtLast(head, 10);
    // insertAtLast(head, 20);
    // insertAtLast(head, 30);
    // insertAtLast(head, 40);
    // insertAtLast(head, 50);

    display(head);

    // Node *del = head->next->next; // delete 30.
    // Node *del = head->next; // delete 20.
    Node *del = head; // delete 10.

    delete_node_without_header(del);
    display(head);

    return 0;
}

/****************************************************************************
File name: check_linkedlist_palindrome.cpp

Author: babajr
*****************************************************************************/


/*
Given the head of a Singly LinkedList, write a method to check if the LinkedList is
a palindrome or not.

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false
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
Node *head1 = NULL; // global head pointer for second list.


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
Helper API to reverse the linked list.
*/
Node *reverse(Node *curr)
{
    // to reverse the link from the curr to previous node.
    Node *prev = NULL;
    while(curr != NULL)
    {
        Node *next = curr->next; // to point to the next node after curr in order to traverse forward even after reversing the link.
        curr->next = prev; // reverse the link.
        prev = curr; // move prev to next node.
        curr = next; // move curr to next node.
    }

    return prev;
}


/*
API to check if given linked list is palindrome or not.

Algo:

--> find middle of linked list.
--> reverse the second half of the linked list.
--> compare the first half with the reversed second half. If found equal, list will be
    palindrome.
--> reverse the second half again to revert and bring back the list again to its
    original form.
*/
bool is_palindrome_linkedlist(Node *ptr)
{
    // Empty list and list with one node will be considered as palindrome.
    if(ptr == NULL || ptr->next == NULL)
        return true;

    // find the middle of the linked list.
    Node *slow = ptr;
    Node *fast = ptr;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow will be the middle node.
    // reverse the second half of the linked list.
    Node *head_second = reverse(slow);
    // store this head to revert back to original list.
    Node *copy_head_second = head_second;

    // compare the two halfs. If equal list will be palindrome.
    while(ptr != NULL && head_second != NULL)
    {
        if(ptr->data != head_second->data)
            break; // not a palindrome.
        ptr = ptr->next;
        head_second = head_second->next;
    }

    // revert the second half.
    reverse(copy_head_second);

    if(ptr == NULL || head_second == NULL)
        return true;
    else
        return false;
}


/*
Brute Force: Using Stack. TC: O(n), SC: O(n)
API to check if given linked list is pallindrome or not.

Algo:
-->
--> Traverse the given list from head to tail and push every visited node to stack.
--> Traverse the list again. For every visited node, pop a node from the stack and
    compare data of popped node with the currently visited node.
--> If all nodes matched, then return true, else false.
*/
bool is_palindrome_linkedlist_bf(Node *ptr)
{
    // create a stack of int values.
    stack <int> st;
    Node *temp = ptr;

    // push all elements of list to the stack
    while(ptr != NULL)
    {
        st.push(ptr->data);
        ptr = ptr->next;
    }

    // traverse the list and check one by one
    // if element popped from stack is equal to current
    // element in the list.
    while(temp != NULL)
    {
        if(temp->data != st.top())
            return false;

        st.pop();
        temp = temp->next;
    }

    return true;
}


int main(void)
{
    // we wil be creating list by inserting elements always at the end.
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 30);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);

    display(head);

    printf("%d\n", is_palindrome_linkedlist(head)); // 1 ==> Palindrome
    printf("%d\n", is_palindrome_linkedlist_bf(head)); // 1 ==> Palindrome

    return 0;
}

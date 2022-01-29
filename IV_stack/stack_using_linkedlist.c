/****************************************************************************
File name: stack_using_linkedlist.c

Author: babajr
*****************************************************************************/


/*
Implementation of stack using linked list physical data structure.

Idea is to push element at the start of linked list and delete / pop element
from the start.
*/


#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *top = NULL; // global top pointer


/*
API to add element to the stack at the top.
*/
void push(int value)
{
    // Create new node.
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Check if the stack is full or not.
    if(newNode == NULL)
        printf("Stack is Full\n");
    else
    {
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
}


/*
API to delete / pop out element from the stack. It will return popped out value.
*/
int pop()
{
    int value = -1; // If stack is empty, we will return -1.
    Node *temp;

    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp = top;
        top = temp->next;
        value = temp->data;
        free(temp);
    }

    return value;
}


/*
API to display the elements of the stack.
*/
void display()
{
    Node *temp = top;

    // Traverse the stack until it becomes empty.
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


/*
API to get the element from the stack present at particular position.
*/
int peek(int pos)
{
    Node *temp = top;

    // Traverse the stack / list upto the given position.
    // return the value at the position.
    // Also, add check for valid position.
    // If position is valid, we will return -1.
    for(int i = 0; (temp != NULL) && (i < (pos - 1)); ++i)
    {
        temp = temp->next;
    }

    // Check if position is valid.
    if(temp != NULL) // means position is valid
        return temp->data;
    else
        return -1;
}


/*
API to check is stack is empty.
*/
int isEmpty()
{
    Node *temp = top;
    if(temp == NULL)
        return 1;
    else
        return 0;
}


/*
API to check is stack is full.
*/
int isFull()
{
    int flag;
    // Stack is full only when there won't be any space remaining in the heap.
    Node *temp = (Node *)malloc(sizeof(Node));
    // check if malloc is unable to allocate more memory. It will return NULL.
    if(temp == NULL)
        flag = 1; // stack is full.
    else
        flag = 0;

    free(temp);
    return flag;
}


/*
API to get the element at the top.
*/
int stackTop()
{
    Node *temp = top;

    // If stack is empty we will return -1.
    if(temp == NULL)
        return -1;
    else
        return temp->data;
}


int main(void)
{
    push(1);
    push(3);
    push(2);
    push(5);
    push(4);

    display();

    // pop();
    // pop();
    // display();

    printf("peek() === %d\n", peek(10));
    printf("isEmpty() === %d\n", isEmpty());
    printf("isFull() === %d\n", isFull());
    printf("stackTop() === %d\n", stackTop());

    return 0;
}

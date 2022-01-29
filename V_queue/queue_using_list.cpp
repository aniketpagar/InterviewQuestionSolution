/*
Queue implementation using Linked List.
*/

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *front = NULL;
Node *rear = NULL;


/*
API to enqueue element in the queue.
*/
void enqueue(int val)
{
    // create new node.
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    // check if Q is full i.e. malloc() will return NULL once heap memory is not free.
    if(newNode == NULL)
        printf("Q is FULL\n");
    else
    {
        // if list is empty.
        if(front == NULL)
        {
            front = newNode; // this will act as head.
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}


/*
API to dequeue element from the queue.
*/
int dequeue()
{
    int x = -1; // return -1 if queue is empty
    Node *temp = NULL;

    if(front == NULL)
    {
        printf("Q is EMPTY\n");
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
    }

    return x;
}


/*
API to display element of the queue.
*/
void display()
{
    Node *temp = front;

    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main(void)
{
    enqueue(1); // 1
    display();
    enqueue(2); // 1 2
    display();
    enqueue(3); // 1 2 3
    display();
    enqueue(4); // 1 2 3 4
    display();
    dequeue(); // 2 3 4
    display();

    return 0;
}

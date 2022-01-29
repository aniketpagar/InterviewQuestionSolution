/****************************************************************************
File name: queue_using_array_simple.cpp

Author: babajr
*****************************************************************************/


/*
Queue implementation using array.
*/

#include<bits/stdc++.h>
using namespace std;


#define MAX_SIZE  100

/* Global variables */
int front = -1;
int rear = -1;
int arr[MAX_SIZE];


/*
API to enqueue element in the queue.
*/
void enqueue(int val)
{
    // check if Q is full
    if(rear == MAX_SIZE - 1)
    {
        printf("Queue is Full\n");
    }
    else // increment rear pointer and insert the value at that location.
    {
        rear++;
        arr[rear] = val;
    }
}


/*
API to dequeue element from the queue.
*/
int dequeue()
{
    int x = -1; // if Q is empty, return -1.

    // check if Q is empty
    if(front == rear)
    {
        printf("Q is empty\n");
    }
    else // increment front pointer.
    {
        front++;
        x = arr[front];
    }

    return x;
}


/*
API to display element of the queue.
*/
void display()
{
    for(int i = front + 1; i <= rear; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}


int main(void)
{
    enqueue(1);
    display();
    enqueue(2);
    display();
    enqueue(3);
    display();
    enqueue(4);
    display();
    dequeue();
    display();

    return 0;
}

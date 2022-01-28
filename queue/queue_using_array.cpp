/*
Queue implementation using array.
*/

#include<bits/stdc++.h>
using namespace std;


struct queque
{
    int size;
    int front;
    int rear;
    int *q_arr;
};

typedef struct queque Q;

/*
API to create the queue initially.
*/
void create(Q *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->q_arr = (int *)malloc(sizeof(int) * q->size);
}


/*
API to enqueue element in the queue.
*/
void enqueue(Q *q, int val)
{
    // check if Q is full
    if(q->rear == q->size - 1)
    {
        printf("Queue is Full\n");
    }
    else // increment rear pointer and insert the value at that location.
    {
        q->rear++;
        q->q_arr[q->rear] = val;
    }
}


/*
API to dequeue element from the queue.
*/
int dequeue(Q *q)
{
    int x = -1; // if Q is empty, return -1.

    // check if Q is empty
    if(q->front == q->rear)
    {
        printf("Q is empty\n");
    }
    else // increment front pointer.
    {
        q->front++;
        x = q->q_arr[q->front];
    }

    return x;
}


/*
API to display element of the queue.
*/
void display(Q *q)
{
    for(int i = q->front + 1; i <= q->rear; i++)
        printf("%d\t", q->q_arr[i]);

    printf("\n");
}


int main(void)
{
    int q_size;
    Q queue;

    printf("Enter Size: \n");
    scanf("%d", &q_size);

    create(&queue, q_size);
    display(&queue);
    enqueue(&queue, 1);
    display(&queue);
    enqueue(&queue, 2);
    display(&queue);
    enqueue(&queue, 3);
    display(&queue);
    enqueue(&queue, 4);
    dequeue(&queue);
    display(&queue);

    return 0;
}

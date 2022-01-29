/*
Implement queue using two stacks. IMPLEMENTATION NOT WORKING.

Algo:
--> use two stacks i.e. stack1 and stack2.
--> For enqueue(x), push in stack1.
--> For dequeue(),
    --> if(stack2 is empty)
        transfer elements from stack1 to stack2.
        then pop() from stack2.
    --> else // if(stack2 is not empty)
        pop() from stack2.
*/


#include <stdio.h>
#include <stdlib.h>

/*==================================================================*/
/*============= STACK IMPLEMENTATION STARTS ========================*/

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
// Node *top = NULL; // global top pointer


/*
API to add element to the stack at the top.
*/
void push(Node **top, int value)
{
    // Create new node.
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Check if the stack is full or not.
    if(newNode == NULL)
        printf("Stack is Full\n");
    else
    {
        newNode->data = value;
        newNode->next = *top;
        *top = newNode;
    }
}


/*
API to delete / pop out element from the stack. It will return popped out value.
*/
int pop(Node **top)
{
    int value = -1; // If stack is empty, we will return -1.
    Node *temp;

    if(*top == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp = *top;
        *top = temp->next;
        value = temp->data;
        free(temp);
    }

    return value;
}


/*============ STACK IMPLEMENTATION ENDS ==========================*/

struct queue
{
    struct Node *enque_stack;
    struct Node *deque_stack;
};

typedef struct queue Q;
Q *q;

/*
API to enqueue element in the queue.
*/
void enqueue(Q *q, int val)
{
    push(&q->enque_stack, val);
}


/*
API to dequeue element from the queue.
*/
int dequeue(Q *q)
{
    int x = -1; // in case of empty stack we will return -1.

    // check for empty stacks
    if(q->enque_stack == NULL && q->deque_stack == NULL)
    {
        printf("ERROR: Empty Stacks\n");
        return x;
    }

    // move elements from enque_stack to deque_stack if deque_stack is empty.
    if(q->deque_stack == NULL)
    {
        while(q->enque_stack != NULL)
        {
            x = pop(&q->enque_stack);
            push(&q->deque_stack, x);
        }
    }

    // pop() from deque_stack.
    x = pop(&q->deque_stack);
    return x;
}


int main(void)
{
    q = (Q *)malloc(sizeof(Q));
    q->enque_stack = NULL;
    q->deque_stack = NULL;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Dequed element: %d\n", dequeue(q));
    printf("Dequed element: %d\n", dequeue(q));
    printf("Dequed element: %d\n", dequeue(q));

    return 0;
}

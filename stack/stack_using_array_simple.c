/*
Here instead of using structure to have arr, size and top, we will use
global array, size and top as a single variables.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE    100

// We will use global array and top
int arr[MAX_SIZE];
int top = -1;

/*API to push the elements on the stack.*/
void push(int val)
{
    // check for stack overflow
    if(top == MAX_SIZE - 1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }

    arr[++top] = val;
}


/*API to pop the elements from the stack.*/
void pop()
{
    // check for empty stack
    if(top == -1)
    {
        printf("ERROR: No element to POP\n");
        return;
    }

    top--;
}


/*
API to return the top element of the stack.
*/
int stack_top()
{
    if(top == -1)
    {
        printf("ERROR: stack is empty\n");
        return -1;
    }

    return arr[top];
}


bool is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}


bool is_full()
{
    if(top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}


/*API to print the elements on the stack.*/
void print_stack()
{
    printf("Stack : ");
    for(int i = 0; i <= top; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


int main(void)
{
    push(1);
    print_stack();
    push(2);
    print_stack();
    push(3);
    print_stack();
    pop();
    print_stack();

    printf("TOP of stack: %d\n", stack_top());

    return 0;
}

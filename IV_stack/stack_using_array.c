/*
Implementation of stack using array physical data structure.

Idea is to push element at the end of array and delete / pop element
from the end.
*/


#include <stdio.h>
#include <stdlib.h>


struct stack
{
    int size; // size of stack.
    int top; // index always pointing to the top of the stack.
    int *s; // pointer to dynamic array.
};

typedef struct stack stack;


/*
API to create the stack. Initialise the stack.
*/
void create(stack *st)
{
    // Ask user to enter the size.
    printf("Enter the size of ARRAY/STACk \n");
    scanf("%d", &st->size);

    // Initially stack is empty i.e. top = -1.
    st->top = -1;

    // create array on the heap.
    st->s = (int *)malloc(sizeof(int) * st->size);
}


/*
API to add element to the stack at the top.
*/
void push(stack *st, int value)
{
    // Check if stack is full or not.
    if(st->top == st->size-1) // -1 as stack index starts from 0.
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // point the top to next element and add the value at top.
        st->top++;
        st->s[st->top] = value;
    }
}


/*
API to delete / pop out element from the stack. It will return popped out value.
*/
int pop(stack *st)
{
    int value = -1; // if stack is empty, return -1.

    // Check if stack is empty.
    if(st->top == -1)
        printf("Stack is Empty\n");
    else
    {
        value = st->s[st->top];
        st->top--;
    }

    return value;
}


/*
API to display the elements of the stack.
*/
void display(stack st)
{
    // Traverse the stack.
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d\t", st.s[i]);
    }

    printf("\n");
}


/*
API to get the element from the stack present at particular position.

pos         index           value in stack
 1             3                  20 <-- top
 2             2                  15
 3             1                  10
 4             0                  5

Relation between Index and Pos ==>
                index = (top - pos) + 1

*/
int peek(stack st, int pos)
{
    int value = -1; // If invalid index, return -1.

    // Check for valid index.
    if((st.top - pos + 1) < 0)
        printf("Invalid Index\n");
    else
        value = st.s[st.top - pos + 1];

    return value;
}


/*
API to check is stack is empty.
*/
int isEmpty(stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}


/*
API to check is stack is full.
*/
int isFull(stack st)
{
    if(st.top == (st.size - 1))
        return 1;
    else
        return 0;
}


/*
API to get the element at the top.
*/
int stackTop(stack st)
{
    if(isEmpty(st) == 0)
        return st.s[st.top];
    else
        return -1;
}


int main(void)
{
    stack st;

    create(&st);

    push(&st, 1);
    push(&st, 3);
    push(&st, 2);
    push(&st, 5);
    push(&st, 4);

    display(st);

    // pop(&st);
    // pop(&st);
    // display(st);

    printf("peek() === %d\n", peek(st, 1));
    printf("isEmpty() === %d\n", isEmpty(st));
    printf("isFull() === %d\n", isFull(st));
    printf("stackTop() === %d\n", stackTop(st));

    return 0;
}

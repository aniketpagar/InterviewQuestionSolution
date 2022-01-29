/****************************************************************************
File name: two_stacks_using_single_array.cpp

Author: babajr
*****************************************************************************/


/*
Implement two stacks using the single array.
*/

#include <stdio.h>
#include <stdlib.h>


struct two_stacks
{
    int top1;
    int top2;
    int size;
    int *arr;
};

typedef struct two_stacks stacks;
stacks st;

/*
Initialise the two_stacks structure.
*/
void create(int size)
{
    st.top1 = -1;
    st.top2 = size;
    st.size = size;
    st.arr = (int *)calloc(sizeof(int), st.size);
}

// void create(int size)
// {
//     st->top1 = -1;
//     st->top2 = size;
//     st->size = size;
//     st->arr = (int *)malloc(sizeof(int) * st->size);
// }


/*
API to push element in the stack 1.
*/
void push_stack1(int val)
{
    // check if stack is full
    if(st.top1 < st.top2 - 1) // space of atleast one element should be empty.
    {
        st.top1++;
        st.arr[st.top1] = val;
    }
    else
    {
        printf("STACK OVERFLOW\n");
        return;
    }
}


/*
API to pop element from the stack 1.
*/
int pop_stack1()
{
    int x = -1;

    // check if stack is empty
    if(st.top1 >= 0)
    {
        x = st.arr[st.top1];
        st.top1++;
    }
    else
    {
        printf("STACK UNDERFLOW\n");
    }

    return x;
}


/*
API to push element in the stack 2.
*/
void push_stack2(int val)
{
    // check if stack is full
    if(st.top1 < st.top2 - 1) // space of atleast one element should be empty.
    {
        st.top2--;
        st.arr[st.top2] = val;
    }
    else
    {
        printf("STACK OVERFLOW\n");
        return;
    }
}


/*
API to pop element from the stack 2.
*/
int pop_stack2()
{
    int x = -1;

    // check if stack is empty
    if(st.top2 < st.size)
    {
        x = st.arr[st.top2];
        st.top2--;
    }
    else
    {
        printf("STACK UNDERFLOW\n");
    }

    return x;
}


/*
API to display elements of the stack.
*/
void display()
{
    printf("STACK 1: \n");
    for(int i = 0; i <= st.top1; i++)
        printf("%d\t", st.arr[i]);

    printf("\n");

    printf("STACK 2: \n");
    for(int i = st.size - 1; i >= st.top2; i--)
        printf("%d\t", st.arr[i]);

    printf("\n");
}


int main(void)
{
    // stacks st;
    // create(&st, 5);
    create(5);
    push_stack1(1);
    push_stack1(2);
    push_stack1(3);
    pop_stack1();
    display();
    push_stack2(4);
    push_stack2(5);
    pop_stack2();
    display();

    return 0;
}

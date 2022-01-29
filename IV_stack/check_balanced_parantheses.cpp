/****************************************************************************
File name: check_balanced_parantheses.cpp

Author: babajr
*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


struct stack
{
    int size; // size of stack.
    int top; // index always pointing to the top of the stack.
    // int *s; // pointer to dynamic array.
    char *s;
};

typedef struct stack stack;


/*
API to add element to the stack at the top.
*/
void push(stack *st, char value)
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
char pop(stack *st)
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
API to get the element at the top.
*/
char stackTop(stack st)
{
    if(isEmpty(st) == 0)
        return st.s[st.top];
    else
        return -1;
}


/*
Helper API to check whether two characters are opening and closing of
same type.
*/
bool are_pair(char opening, char closing)
{
    if(opening == '(' && closing == ')')
        return true;
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;

    return false;
}


/*
API to check for balanced parantheses using the stack data structure.

Algo:
--> scan the array from the left to right.
--> while scanning,
    --> if(str[i] == ( == { == [) i.e. char is opening symbol
        then push it to the stack
    --> if(str[i] == ) == } == ]) i.e. char is closing symbol
        then, pop last opening symbol from stack
        check if closing and opening symbol matches.
    --> if at the end of string, if stack becomes empty, means
        expression ==> BALANCED PARANTHESES.
*/
bool are_balanced_parantheses(char *exp)
{
    // create stack to store the opening and closing symbols.
    stack st;
    st.size = strlen(exp);
    st.top = -1;

    st.s = (char *)malloc(sizeof(char) * (st.size));

    // traverse the expression from left to right
    for(int i = 0; i < st.size; i++)
    {
        // check for opening brackets and push them to the stack.
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&st, exp[i]);
        }
        // check for the closing brackets.
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(st) == 1 || are_pair(stackTop(st), exp[i]) != 1)
            {
                return false; // not balanced parantheses.
            }
            else
                pop(&st);
        }
    }

    if(isEmpty(st) == 1)
        return true;
    else
        return false;
}


int main(void)
{
    // char str[] = "{(a+b)*(a-b)}";
    char str[] = "{";

    if(are_balanced_parantheses(str) == 1)
        printf("YES balanced parantheses. \n");
    else
        printf("NOT balanced parantheses. \n");
    return 0;
}

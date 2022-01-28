/*
Implementation of Stack using queues.
*/

#include<bits/stdc++.h>
using namespace std;


/*
Using 2 QUEUES.

Algorithm:
--> create two queues. Q1 and Q2.
--> push(x):
    --> enqueue(Q2, x) ==> add x to Q2.
    --> transfer elements from Q1 to Q2 element by element.
    --> swap elements between Q1 and Q2. i.e swap the names of two queues.
        swap(Q1, Q2)

--> pop():
    --> remove the top of Q1.
        dequeue(Q1).
*/

queue<int> Q1, Q2;
int curr_size = 0;

void push(int x)
{
    curr_size++;

    // add elements to Q2.
    Q2.push(x);

    // transfer the elements from Q1 to Q2.
    while(Q1.empty() != true)
    {
        Q2.push(Q1.front());
        Q1.pop();
    }

    // swap the names of two queues
    //swap(Q1, Q2);
    queue<int> Q3 = Q1;
    Q1 = Q2;
    Q2 = Q3;
}


void pop()
{
    //if stack is empty.
    if(Q1.empty() == true)
        return;

    Q1.pop();
    curr_size--;
}


int top()
{
    if(Q1.empty() == true)
        return -1;

    return Q1.front();
}


int size()
{
    return curr_size;
}

int main(void)
{


    return 0;
}

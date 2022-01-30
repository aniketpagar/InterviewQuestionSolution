/****************************************************************************
File name: queue_using_array_simple.cpp

Author: aniket pagar
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;
#include "iostream"

#define MAX_SIZE  3

/* Global variables */
int front = -1;
int rear = -1;
int arr[MAX_SIZE];
int dataElementStored;// it gives the total element stored in queue

/*
API to enqueue element in the queue.
*/
void enqueue(int val)
{
    // check if Q is full
    if(dataElementStored == MAX_SIZE)
    {
        cout<<"\n Queue is Full"<<endl;;
    }
    else 
    {
        front++;
        if(front == MAX_SIZE)
        {
            front = 0; //to make it cyclic
        }
        arr[front]=val;
        if(dataElementStored == 0){ //queue is empty
           rear = front; // to make rear & front at same place i.e this is enque call & we are going to add one element 
                        // so our rear & front should point to same location 
        }
        dataElementStored++;
    }
}


/*
API to dequeue element from the queue.
*/
void dequeue()
{
    // check if Q is empty
    if(dataElementStored == 0)
    {
        cout<<"\n queue is empty"<<endl;
        front = -1;rear =-1;
    }
    else 
    {
        rear++;
        dataElementStored--;
        if(rear  == MAX_SIZE)
            rear =0;//to make it cyclic
    }
}


/*
API to display element of the queue.
*/
void display()
{
    cout<<" \n DISPLAY : "<<endl;
    if(!dataElementStored)
    {
        cout<<" No data is present in queue"<<endl;return;
    }

    int temp = dataElementStored;
    int r=rear;
    int f=front;

    while(temp > 0)
    {
        cout<<" : "<<arr[r];
        r++;
        if(r == MAX_SIZE )
        {
           r = 0; //to traverse the cycle
        }
        temp--;
    }
}


int main(void)
{
    enqueue(1);//1
    //display();
    enqueue(2);//1 2
    //display();
    enqueue(3);//1 2 3 
    //display();
    enqueue(4); //Queue is Full 
   // display();
    dequeue();//2 3
    display();// 2 3
    dequeue();// 3
    display();//3 
    enqueue(5);//
    display();// 3 5 
    enqueue(9);
    display();//3 5  9
    enqueue(5);//Queue is Full
    display();//3 5 9
    dequeue();
    dequeue();
    dequeue();
    dequeue();//Queue is empty
    enqueue(8);
    display();//8
    dequeue();
    display();//empty
    enqueue(11);enqueue(12);dequeue();enqueue(99);
    display();//12 99
    return 0;
}
/*
OUTPUT - 
    Queue is Full

    DISPLAY :
    : 2 : 3
    DISPLAY :
    : 3
    DISPLAY :
    : 3 : 5
    DISPLAY :
    : 3 : 5 : 9
    Queue is Full

    DISPLAY :
    queue is empty

    DISPLAY :
    : 8
    DISPLAY :
    No data is present in queue

    DISPLAY :
    : 12 : 99
*/
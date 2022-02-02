/*
    author :  aniket
    question asked in synopsis
*/

#include "iostream"
using namespace std;
#include "string"

#define stacksize 100
class dStack
{
    public:
    int arr[stacksize];
    int front, rear;
    dStack()
    {
        front =-1;
        rear = -1;
    }
    
    void push(int n )
    {
        if(front == stacksize-1)
        {
            cout<<" stack overflow"<<endl;
        }else
        {
            front++;
            arr[front]=n;
        }
    }
    
    int pop()
    {
        if(front == -1)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else
        {   
            return arr[front--];
        }
    }
    
};

int main()
{
    
    int input = 10;
    string binaryNum;
    
    dStack obj;
    int tmp=input;
    
    while(tmp != 0)
    {
        if(tmp%2)
        {
            obj.push(1);
        }
        else
        {
            obj.push(0);
        }
        tmp= tmp/2;
    }
    
    cout<<"decimal num : "<<input<<" binary : ";
    while(obj.front != -1)
    {
        cout<<" "<<obj.pop();
    }
    
}

/*
    OUTPUT : -
        decimal num : 10 binary :  1 0 1 0
*/

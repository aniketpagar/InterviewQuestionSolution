
/*
Function pointers can be useful when you want to create callback mechanism, 
and need to pass address of a function to another function.
*/
#include "iostream"
using namespace std;
void display()
{
   cout<<"\n i am in display function\n";
}
int add(int x , int y)  
{  
    cout<<" \n i am in add function\n";
    return x+y;  
}  
int main()
{
    int (*funcPtr)(int,int);
    funcPtr = add;
    funcPtr(2,3);

    void (*funcPtr1)();
    funcPtr1=display;
    funcPtr1();
    
}
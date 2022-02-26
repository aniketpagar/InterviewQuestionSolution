#include "iostream"
using namespace std;

int main()
{
    int  x =1;

    try{
        cout<<" i am inside try"<<endl;
        if(x<2)
           throw x;//here we are throwing exception that will land on catch
    }
    catch(int k)
    {
        cout<<" exception occure for number : "<<k<<endl;
    }
}

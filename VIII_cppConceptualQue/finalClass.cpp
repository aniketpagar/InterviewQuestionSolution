
/*
    final specifier in C++ 11 can also be used to prevent inheritance of class / struct. If a class or 
	struct is marked as final then it becomes non inheritable and it cannot be used as base class/struct. 
*/
#include "iostream"
using namespace std;
class aniket final
{
    public:
    aniket()
    {
        cout<<" i am in a constructor"<<endl;
    }
};
//class pagar:public aniket // error: cannot derive from 'final' base 'aniket' in derived type 'pagar'
class pagar
{
    public:
    pagar()
    {
        cout<<" i am in constructor"<<endl;    
    }
};
int main()
{

}
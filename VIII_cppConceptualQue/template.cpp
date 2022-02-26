#include "iostream"
using namespace std;

//template function can be overload
template <class T>
T add(T a,T b)
{
    cout<<" add the same type of data";
   return(a+b);
}
template <class T, class T1>
T1 add(T a,T1 b)
{
    cout<<" add the different type of data";
    return a+b;
}
int main()
{
   
   cout<<add(2,3)<<endl;
   cout<<add(2,3.3)<<endl;
}
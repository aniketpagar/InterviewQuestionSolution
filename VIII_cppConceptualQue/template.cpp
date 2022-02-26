#include "iostream"
using namespace std;


//template class
template<class T>
class aniket
{
    public:
    T a;
    aniket()
    {}
    aniket(T d)
    {
        this->a=d;
    }
};

//template function can be overload
template <class T>
T add(T a,T b)
{
    cout<<" add the same type of data "<<endl;
   return(a+b);
}
template <class T, class T1>
T1 add(T a,T1 b)
{
    cout<<" add the different type of data "<<endl;
    return a+b;
}
int main()
{
   cout<<add(2,3)<<endl;//template function
   cout<<add(2,3.3)<<endl;//template function

    //template class object creation
    aniket<int>a1;
    cout<<a1.a<<endl;
    aniket<int>a2(2);
    cout<<a2.a<<endl;
  
}
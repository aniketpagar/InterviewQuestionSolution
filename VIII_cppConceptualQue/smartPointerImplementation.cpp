/*
    simplest implementation of smart pointer 
    1. to allocate memory of any type
    2. auto delete memory
*/

#include "iostream"
using namespace std;

class aniket
{

    public:
    int a;
    aniket()
    {}
    ~ aniket()
    {
    }
    aniket(int k )
    {
        a = k;
    }
    void display()
    {
       cout<<"I am in a display\n";
    }
};

template <class T>
class sp 
{
    T*   pData;//generic pointer to be store

    public:
    sp(T* val): pData(val)
    {
    }

    ~sp()
    {
       cout<<" I am deleting memory assigned to pointer\n";
        delete pData;
    }
    T& operator*()
    {
        return *pData;
    }

    T* operator->()
    {
        return pData;
    }

};

int main()
{
   sp<aniket> p(new aniket);
   p->display();
}
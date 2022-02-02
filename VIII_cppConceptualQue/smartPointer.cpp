#include "iostream"
using namespace std;
#include "memory" //header to add smart pointer

class aniket
{
    public:
    int a, b;
    aniket(int a, int b)
    {
        this->a=a;
        this->b=b;
    }
};

int main()
{
    //unique_ptr
    unique_ptr<aniket>p1(new aniket(1,2));//only one owner
    cout<<"a : "<<p1->a<<endl;
    unique_ptr<aniket> p2;
    p2 =move(p1);// change the owner
    //cout<<"a : "<<p1->a<<endl;//this will crash, p1 dont have a memory now.
    cout<<"a : "<<p2->a<<endl;
    cout<<"size of unique pointer : "<<sizeof(p2)<<endl;


    //shared_ptr
    //this type of pointer shared among multiple api.
    //By using shared_ptr more than
    //one pointer can point to this one object at a time and
    //it’ll maintain a Reference Counter using use_count() method. 

    shared_ptr<aniket>a1(new aniket(9,8));
    cout<<a1->a<<endl;
    cout<<"size of shared pointer : "<<sizeof(a1)<<endl;


    /*weak_ptr
     A weak pointer is a smart pointer that does not take ownership of an object
     but act as an observer. In other words, it does not participate in reference counting 
     to delete an object or extend its lifetime. Weak pointers are mainly used to
     break the circular dependency that shared pointers create.
     */
    weak_ptr<aniket>w1{a1};
}
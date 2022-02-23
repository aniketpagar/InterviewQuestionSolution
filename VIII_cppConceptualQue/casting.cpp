#include "iostream"
using namespace std;
class base
{
    public:
    base(){};
    virtual void display(){
        cout<<" I am in base display"<<endl;
    };

};
class derived :public base
{
    public:
    int data;
    void funToTestConst_Cast(int d) const
    {
        //data = d;//this gives the compilation error 
        (const_cast<derived*>(this))->data = d;
    }
    derived(){};
    void display()
    {
        cout<<" I am in derived display"<<endl;
    }
};
int main()
{
    //static_cast
    float i = 1.2;
    int j = i;
    int k= static_cast<int>(i);
    cout<<"i : "<<i<<" j : "<<j<<" k : "<<k<<endl;

    //dynamic cast;
    //If you want to use a dynamic cast for downcasting,
    //the base class should be polymorphic – it must have at least one virtual function.

    
    base b;
    derived d;
    base b10 = static_cast<base>(d);//upcasting
    //derived d10 = dynamic_cast<derived&>(b);//downcasting
    //d = static_cast<derived>(b);// this will give compilation error
    //d = dynamic_cast<derived>(b);//compilation error - dynamic_cast must be a pointer or reference.

   
    base *b1 = new derived;//polymerphism
    b1->display();
    //upcast
    b1 = dynamic_cast<base*>(b1);//dynamic_cast must have a polymermic class
    b1->display();
   
   //downcast
   derived *d12 = dynamic_cast<derived*>(b1);
   d12->display();

   //const_cast
   //const_cast can be used to change non-const class members inside a const member function
    d12->funToTestConst_Cast(12);
    
    
   //reinterpret_cast 
   //It can typecast any pointer to any other data type.
    int *k;
   //char *ank = dynamic_cast<char*> (k);//will give compilation error
   char *ank = reinterpret_cast<char*> (k);
}
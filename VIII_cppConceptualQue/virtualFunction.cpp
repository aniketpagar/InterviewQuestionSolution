/*
https://thispointer.com/how-virtual-functions-works-internally-using-vtable-and-vpointer/

Constructor can not be virtual, because when constructor of a class is executed there is no vtable in the memory
virtual distructor require bcz

vTable:

Every class that has one or more virtual member functions in it has a vTable associated with it.
vTable is a kind of function pointer array that contains the addresses all virtual functions of this class.
 Compiler builds this vTable at compile time.

vPointer:

Now for every object of a class that has a vTable associated with it, contains a vPointer in first 4 bytes. 
This vPointer points to the vTable of that class.
This vPointer will be used to find the actual function address from vTable at run rime.

Now for every object of a class that has a vTable associated with it, contains a vPointer in first 4 bytes.
This vPointer points to the vTable of that class.
This vPointer will be used to find the actual function address from vTable at run rime.

no of vtable = 1(Number of class)
no of vptr = Num of object;


Once a function is declared virtual in a class then for all its derived classes that function will remain virtual. 
Therefore in above class NewMessageConverter even if we haven’t 
declared convert function virtual but it will be considered as virtual because in its base class this function is virtual.



why we need virtual distructor
    Now, suppose you create an instance of the Derived class using a Base class pointer.
    When you delete the pointer object using the delete keyword in C++, the destructor of the Base class would be called
    but the destructor of the Derived class would simply be ignored. The reason is that the destructor is simply
    another method and so when the delete keyword is used to delete the pointer instance, 
    the type of the pointer would be considered and not its context. And, because the type of the pointer is of type Base,
    the destructor of the Base class would only be invoked. This might create memory leaks as the instance of the derived class would still 
    remain in memory even after the pointer instance has been deleted/destroyed from memory. 
    To avoid such potential memory leak issues, virtual destructors are used.

    we cannot overload a destructor of a class in C++ programming.
    we can overload a constructor of a class in C++ programming.
*/
#include "iostream"
using namespace std;

class base
{
    public:
     base()
    {
    }
    virtual void display()
    {
        cout<<"I am in a base display function"<<endl;
    }
     virtual ~ base()
    {
        cout<<"virtual base destructor called"<<endl;
    }
};

class derived:public base 
{
    public:
    derived()
    {
    }
    void display()
    {
        cout<<"I am in a derived display function"<<endl;
    }
    ~ derived()
    {
        cout<<"derived distructor called"<<endl;
    }
};

int main()
{
    derived *d= new derived;

    base *b=d;
    b->display();
    delete b;
    /*
         if distructor is virtual then only derived & base destructor get called
         otherwise only base constructor get called on deleting the obj.
    */
    
}
/* output : 
        I am in a derived display function
        derived distructor called
        virtual base destructor called
*/
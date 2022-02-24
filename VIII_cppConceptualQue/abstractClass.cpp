/*
    an abstract class in C++ is a class that has at least one pure virtual function 
    (i.e., a function that has no definition). The classes inheriting the abstract class
     must provide a definition for the pure virtual function; 
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class base
{
    public:
    base(){}
    virtual void display()=0;//pure virtual function
};
class derived : public base
{
    public:
    derived(){}
    void display()
    {
        cout<<"I am in a display function";
    }
};
int main()
{
    base *b1= new derived;
    b1->display();

}

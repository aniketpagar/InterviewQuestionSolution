/*
    author : aniket
*/

#include "iostream"
using namespace std;

// C++ program to find length of an array by writing our
// sizeof
#include <bits/stdc++.h>
using namespace std;

// User defined sizeof macro
#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
class stringTemp
{
public:
    char *s;
    int length;
    //default constructor
    stringTemp()
    {
        s = NULL;
    }

    //parameterised constructor
    stringTemp(char input[])
    {
        length= 0;
        //cal the length of string
        while(input[length] !='\0'){
            length++;
        }
        this->s = new char[length];//assign the memory to the pointer
        int i =0;
        //stored the string inside the pointer.
        while(i != length){
            s[i] = input[i];
            i++;
        } 
    }

    //desturctor
    ~stringTemp()
    {
        cout<<" I am in destructor"<<endl;
        if (s != NULL)
        {
            delete s;
            s = NULL;
        }
    }

    //copy constructor
    stringTemp(const stringTemp &obj)
    {
        this->s = obj.s;
        this->length = obj.length;
    }

    //move constructor
    stringTemp(stringTemp &&obj)
    {
        cout<<"I am in a move constructor"<<endl;
        this->s = obj.s;
        this->length = obj.length;
        obj.length = 0;
        obj.s = NULL;
    }

    //string length
    int slength()
    {
        return this->length;
    }

    //assign operator
    stringTemp &operator=(const stringTemp &obj)
    {
        this->s = obj.s;
        this->length = obj.length;
        return *this;
    }
};
int main()
{
    stringTemp obj("aniket");
    cout <<"length of obj string : "<<obj.slength()<<endl;//calculate the length of string

    stringTemp obj1= obj;//copy constructor(copy the string)
    cout <<"length of obj1 string : "<<obj1.slength()<<endl;

    stringTemp obj2;
    obj2 = obj1;//assign operator(assign the string)
    cout <<"length of obj2 string : "<<obj2.slength()<<endl;

    stringTemp obj5= move(obj1);//move constructor(move the string)
    cout <<"length of obj5 string : "<<obj5.slength()<<endl;
}

/* output -

        length of obj string : 6
        length of obj1 string : 6
        length of obj2 string : 6
        I am in a move constructor
        length of obj5 string : 6
*/
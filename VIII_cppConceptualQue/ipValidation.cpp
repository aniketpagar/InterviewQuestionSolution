/* this is simplex prgrm to validate the ipv4
NOTE : some -ve case can be added
*/

#include "iostream"
using namespace std;
#include "string.h"
#include <iostream>
bool isValidIpv4(string a)
{
    cout<<" the IP : "<<a<<" ";
    int count =0;//to count the iteger present in the ip; it should be 4
    string temp;
    for(int i =0; i <a.length();i++)
    {
        //number should be integer
        if ((a[i] >= '0' && a[i] <= '9' || a[i] =='.') == false)
        {
            //cout<<" whats wrong -> "<<a[i]<<endl;
            return false;
        }
        if(a[i] =='.')
        {
            int i = stoi(temp);
            //cout<<i<<endl;
            if(i >255)
                return false;
            temp.clear();
            count++;
        }
        else
        {
            temp = temp + a[i];//collect the number till  . 
        }
    }
    //check the last integer, that has stored in temp;
     int i = stoi(temp);
     //cout<<i<<endl;
     if(i >255)
        return false;
    count++;
    if(count != 4)
            return false;
    return true;
}
int main()
{
    string a("12.2.2.67");
    if(isValidIpv4(a))
        cout<<" is valid"<<endl;
    else
        cout<<" is not valid"<<endl;

    string a1("12.2323.2.67");
    if(isValidIpv4(a1))
        cout<<" is valid"<<endl;
    else
        cout<<" is not valid"<<endl;

    string a2("12.2.2w.67");
    if(isValidIpv4(a2))
        cout<<" is valid"<<endl;
    else
        cout<<" is not valid"<<endl;
}

/*
    OUTPUT - 
            the IP : 12.2.2.67  is valid
            the IP : 12.2323.2.67  is not valid
            the IP : 12.2.2w.67  is not valid

*/
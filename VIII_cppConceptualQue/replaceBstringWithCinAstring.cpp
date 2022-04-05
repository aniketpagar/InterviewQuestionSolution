/*
Question: You have given string s1, s2, and s3. Write a program to replace the occurrence of an s2 string in s1 with s3 string

*/

#include "iostream"
using namespace std;
#include "vector"
#include "string"

string replaceBwithC(string a, string b, string c)
{
    string ans;
    int i =0;
    while(i != a.size())
    {
        int j =0;
        int k = i;
        while(a[k] == b[j] && j < b.size())
        {
            k++;
            j++;
        }
        if( j == b.size())
        {
            ans = ans + c;
            i = k-1;
        }
        else
        {
            ans = ans + a[i];
        }
        i++;
    }
    return ans;
}
int main()
{
  
    string a("aniketpagaraniketpagarnampuraniketpagar");
    string b("aniket");
    string c("ANIKET");
    cout<<"input :  "<<a<<endl;
    cout<<"output : "<<replaceBwithC(a,b,c);
}

/*
    input :  aniketpagaraniketpagarnampuraniketpagar
    output : ANIKETpagarANIKETpagarnampurANIKETpagar
*/
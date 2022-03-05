/*
Given a string and an integer k, find the number of substrings in which all the different characters occur exactly k times. 

Examples: 

Input : s = "aabbcc"
        k = 2 
Output : 6
The substrings are aa, bb, cc,
aabb, bbcc and aabbcc.

Input : s = "aabccc"
        k = 2
Output : 3
There are three substrings aa, 
cc and cc
*/

#include "iostream"
using namespace std;
#include "string"
#include "vector"

bool checkOtherIndexValue(vector<int>dp, int k)
{
    for(auto it:dp)
    {
       if(it && it != k)
       {
          return false;
       }
    }
    return true;
}
int numofperfectsubstring(string a, int k)
{
    int ans=0;
    int n = a.length();
    for( int i =0;i<n;i++)
     {
         vector<int>dp(26,0);   
         for(int j =i; j<n;j++)
         {  
            int index = a[j]-'a';
            dp[index] = dp[index]+ 1;
            if(dp[a[j]]>k)
               break;
            else if ( dp[index] == k && checkOtherIndexValue(dp,k))
            {
                cout<<a.substr(i,j-i+1)<<endl;;
                ans++;
            }

         }
     }
    return ans;
}

int main()
{
    string a("aabbcc");
    int k =2; // it denotes the substring is allowed with k repeatation
    cout<<numofperfectsubstring(a, k)<<endl;
    cout<<"----------------------------------------"<<endl; 
    string a1("aabbc");
    cout<<numofperfectsubstring(a1, 2)<<endl;
}
/*
output - 
            aa
            aabb
            aabbcc
            bb
            bbcc
            cc
            6
            ----------------------------------------
            aa
            aabb
            bb
            3

*/
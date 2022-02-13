/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

*/


#include "iostream"
using namespace std;
#include "string"
#include <algorithm>

int minDist( string a, string b)
{  
    int lengthA = a.length(), lengthB = b.length();

    int dp[lengthA+1][lengthB+1];

    //dynamic programing approach
    for(int i =0; i<=lengthA;i++)
    {
        for(int j=0;j<=lengthB;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = max(i,j); // to fill the 1st row & first column data
            else
                {
                    if(a[i-1]==b[j-1]) // if both the character are same i.e. then operation require are same as to previous index string.
                    {
                        dp[i][j]= dp[i-1][j-1];
                    }else // to calculate min of all previous three and add one into the min result.
                    {
                        dp[i][j] = min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]}) +1;
                    }
                } 
        }
    }
    // display index
    cout<<" dynamic element stored as below :-> "<<endl;
    for(int i =0; i<=lengthA;i++)
    {
        for(int j=0;j<=lengthB;j++)
        {
            cout<<" "<<dp[i][j];
        }
        cout<<endl;
    }
    cout<<" ans : ";

        return dp[lengthA][lengthB];
}
int main()
{
    string a = "pqqrst";
    string b = "qqttps";
    cout<<minDist(a,b)<<endl;
}

/*

output = 

ans = 5

*/
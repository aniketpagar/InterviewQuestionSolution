/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', 
find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.
*/
#include "iostream"
using namespace std;
#include "string"
#include "vector"
#include "stack"
int lengthOfLongestValidParanthesis(string s, int &start, int &end)
{
    // if(input.empty())return 0;

    // int len = input.length();
    // int i = 0, j=0;
    // int ans=1;
    // int right=0,left=0;
    // while(j<len)
    // {
    //     if(input[j]=='(')
    //        left++;
    //     else
    //       right++;
    //     if(right == left)
    //     {
    //       //ans = max(ans,j-i+1);//using below if case to store the index of substring
    //       //if two valid pattern is having same length then it will store last pattern.
    //       if(ans<=j-i+1)
    //       {
    //           ans=j-i+1;
    //           start = i;
    //           end = j;
    //        }
    //     }else if (right>left)
    //     {
    //         right=0;
    //         left=0;
    //         i = j+1;
    //     }
    //     j++;
    // }
  // return ans;

      if( s.length()==0 || s.length()==1  )
            return 0;
        stack<int>st;
        int count =0;
        for( int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if( ch == '(')
                st.push(i);
            else  if(!st.empty() && s[st.top()] == '(')
                        st.pop();
            else
                st.push(i);
            int temp=st.empty()?-1:st.top();
            count =max(count,i-temp);    
           
        }
        return count;

}
int main()
{
    string a("))())()())(()))");
    int start, end;
    cout<<"substring length :"<<lengthOfLongestValidParanthesis(a, start, end)<<endl;;
    // cout<<"substring pattern : "<<a.substr(start,end-start+1)<<endl;
}
/*

output- 
substring length :4
substring pattern : (())

*/
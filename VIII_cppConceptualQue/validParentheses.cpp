#include "iostream"
using namespace std;
#include "stack"

    bool isValid(string s) {
        
        stack<char> stk;
        
        for(int i=0; i<s.length(); i++)
        {
            if((s[i] == '[') || (s[i] == '{') || (s[i] == '('))
                stk.push(s[i]);
            else
            {
                if(stk.empty())
                    return false;
                else if((s[i] == ']') && (stk.top() != '['))
                    return false;
                else if((s[i] == '}') && (stk.top() != '{'))
                    return false;
                else if((s[i] == ')') && (stk.top() != '('))
                    return false;
                else
                    stk.pop();
            }
        }
        
       return stk.empty();
      
    }
int main()
{
    string paranethese("(())({[]})");
    if(isValid(paranethese))
        cout<<" parentheses are valid"<<endl;
    else    
        cout<<" parentheses are not valid"<<endl;
}
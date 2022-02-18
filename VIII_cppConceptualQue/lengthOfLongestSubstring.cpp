#include "iostream"
using namespace std;
#include "string"
#include "vector"
string lengthOfLongestSubstring(string input)
{
    if(input.empty())return "";
    //window sliding
    int len = input.length();
    int i = 0, j=1;
    vector<bool>ht(300,false);
    int ans=1;
    ht[input[0]] = true;
    int start,end;
    while(j<len)
    {
        if(ht[input[j]])
        {
            ht[input[i]]=false;
            i++;
        }else
        {
            if(ans<=j-i+1)
            {
                start =i;
                end=j;
                cout<<"start : "<<start<<" end : "<<end<<endl;
                ans = j-i+1;
            }
            ht[input[j]] = true;
            j++;
        }
    }
  cout<<"substring : "<<input.substr(start,end-start+1)<<endl;
  cout<<"length Of Longest Substring :"<<ans<<endl;
  return "";

}
int main()
{
    string a("aaanikettttt");
    lengthOfLongestSubstring(a);
}
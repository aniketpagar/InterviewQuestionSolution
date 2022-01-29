#include "iostream"
using namespace std;
#include "string"
#include "vector"

string longestSubstring(string temp)
{
    if(temp.empty())return "";

    vector<bool> v1(26,false);//initilise all with false, it works as a hash table
    int ans = 1;
    int i(0), j(1);
    v1[temp[i]]= true;
    
    int size = temp.length(); 
    int m,n;
    while(j!= size)
    {
        //cout<<temp.substr(i,j-i)<<endl; // debug log to see the window pattern
        if(v1[temp[j]])
        {
            if(ans <= j-i)//if two same length substring present then  it will store the index for the last substring
            {
                //store the index  m & n;
                m = i;
                n = j;
                //cout<<"m : "<<m<<" & n : "<<n<<endl;
            }
            ans = max(ans, j-i);

            v1[temp[i]] = false;
            i++;
        }else{
            v1[temp[j]] = true;
            j++;
        }
    }
    
    cout<<"length of the longest subString: "<<ans<<endl;
    return temp.substr(m,n-m);
}
int main()
{
    string s("lllAniketKKKPagar");
 
    string s1 =longestSubstring(s);
    cout<<"longestSubstring : "<<s1<<endl;
}

/* output : - 
        length of the longest subString: 8
        longestSubstring : lAniketK
*/
//Find k numbers with most occurrences in the given array
//arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, 
//k = 2
//Output: 4 1
#include <iostream>
using namespace std;
#include <vector>
#include "map"
#include "queue"
vector<int> maxOccuranceNum(vector<int>a,int k)
{
    if(k > a.size())
        return {};
    vector<int>ans;
    map<int,int>temp;
    for(auto i:a)
    {
        temp[i]=temp[i]+1;
    }

    priority_queue<pair<int,int>> pq;

     for(auto i:temp)
    {
        pq.push(make_pair(i.second,i.first));
        // pq.push({i.second,i.first});    
    }
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
//another way to find the max occcurance
    // map<int,int,greater<int>>temp1;
    // for(map<int,int>::iterator it= temp.begin();it != temp.end();it++)
    // {
    //    temp1[it->second]=it->first;
    //    cout<<" "<<it->second<<" : "<<it->first<<endl;
    // }

    // for(map<int,int>::iterator it= temp1.begin();it != temp1.end();it++)
    // {
    //     if(k==0)
    //         break;
    //         k--;
    //     ans.push_back(it->second);
    // }

    return ans;
}
int main()
{
    vector<int> a={1,1,1,2,2,3};


    for(auto i: maxOccuranceNum(a,2))
    {
        cout<<i<<" ";
    }
}
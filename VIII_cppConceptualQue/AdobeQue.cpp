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
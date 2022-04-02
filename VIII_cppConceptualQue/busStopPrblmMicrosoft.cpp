/*
1. there are exactly n bus stops from tracy's coacng center to her home.
 the number of buses that can be boarded from each bus stop is also given.
 a bus will only stop at a bus stop whose number is amultiple of the bus stop number from which the bus originates. 
find the number of buses originatingfrom each bus stop between her coacng center and her home.​
input - 1 2 3
output - 1 1 2

input  - 2 7 
output - 2 5
*/
#include "iostream"
using namespace std;
#include "vector"
vector<int> numOfBusOriginateFromEachBusStop(int n , vector<int>v)
{
    int i =2, j=0;
    
    while(i != n+1)
    {
        int j  =1 ;//from 1st bus stop
        while(j != i)
        {
            if(i%(j)==0)
            {
                v[i-1] = v[i-1]-v[j-1];
            }
            j++;
        } 
        i++;
    }
    return v;

}
int main()
{
    vector<int> v1{1,2,3,4,5,6};
    int n = v1.size();
    vector<int>ans = numOfBusOriginateFromEachBusStop(n,v1);
    for(auto  i : ans)
    {
        cout<<i<<" ";
    }
}
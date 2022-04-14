/*
Problem Statement
Given an array of integers and a value, determine if there are any three integers in the array whose sum equals the given value.

Consider this array and the target sums.


*/

//ADOBE
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
bool find_sum_of_two(vector<int>& arr, int remainSum, size_t start_index) {

    int j = arr.size();
    for(int i = start_index; i != j;)
    {
        cout<<" i :"<<i<<" j : "<<j<<" Sum :"<<arr[i]+arr[j]<<endl;
        if(arr[i]+arr[j] == remainSum)
          return true;
        
        if(remainSum <arr[i]+arr[j])
           j--;
        else
          i++;
    }
    return false;
}

bool find_sum_of_three_v3(vector<int> arr,int required_sum) {

    sort(arr.begin(),arr.end());

    for(int i =0; i < arr.size();i++)
    {
        int remainSum = required_sum - arr[i];
        cout<<" remain sum :"<<remainSum<<endl;
        if(find_sum_of_two(arr,remainSum, i))
            return true;
    }   
    return false;
}

int main(){
    vector<int> arr = {-25, -10, -7, -3, 2, 4, 8, 10};
  
    if(find_sum_of_three_v3(arr, -42))
       cout<<" present"<<endl;
    else
       cout<<" not present"<<endl;
  
    return 0;
}
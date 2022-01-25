
/*
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
*/

//Solution =>
//Time complexity  O(N).
//space complexity O(1)


#include "iostream"
using namespace std;
#include "vector"

int main()
{
  int arr[] = { 2, 1, 5, 1, 3, 2}; // in real question, this should be the input
  int k = 3; // in real question, this should be the input
  int maxSum, sum;
  vector<int> result;

  int size = sizeof(arr)/4;
  cout<<" size of array : "<<size<<endl;

  if (size < k)
    return 0;// Invalid length of array received.

   int i = 0;
  
  //first calculate the first k element sum then apply sliding window approach
   while(i != k)
   {
      sum = sum+arr[i];
      result.push_back(arr[i]);
      i++; 
   }
   cout<<"first k element sum is : "<<sum<<endl;
   maxSum = sum;// lets consider first k element sum is a max sum

   //this is slinding window approach
  for (int i = 0; i < size -k ;i++)
  {
      sum = sum - arr[i] + arr[i + k];

      //store the index into result vector; //require only if asked in the questions
      //NOTE: only one window is having max sum
      if(sum > maxSum)
      {
           maxSum= sum;
           result.clear();
           for(int j =i+1; j <= i+k; j++)
           {
               result.push_back(arr[j]);
           }
      }
  }

//diplay the result; 
//in coding exam , we have to return these value
    cout<<"maxSum : "<<maxSum<<endl;
    cout<<"Subarray with maximum sum is [ ";
    for(auto it:result)
       cout<<it<<" ";
    cout<<"]";
}
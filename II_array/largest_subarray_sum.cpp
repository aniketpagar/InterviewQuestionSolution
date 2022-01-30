/****************************************************************************
File name: largest_subarray_sum.cpp

Author: babajr
*****************************************************************************/


/*
Find the largest possible subarray sum in a given array.

Input: {1,2,-3,4,1}
Output: 5
*/


#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Approach.
Calculate sum of all possible subarrays. Return maximum sum.
*/
int largestSubarrSum(int arr[], int size)
{
    int maximum_sum = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        // int subarr_sum = 0;

        for(int j = i; j < size; j++)
        {
            int subarr_sum = 0;
            for(int k = i; k <= j; k++)
            {
                subarr_sum += arr[k];
            }
            // subarr_sum += arr[j];

            maximum_sum = max(maximum_sum, subarr_sum);
        }
    }

    return maximum_sum;
}


/*
Kadane's Algorithm.
Idea is to calculate cumulative sum as we traverse the array. Whenever subarr_sum becomes -ve,
change it to 0. And updating max_sum whenever subarr_sum exceeds max_sum.

arr ->         -2       3       4       -1      5       -12     6       1       3
subarr_sum      0       3       7        6      11  (-1) 0      6       7       10
(0)
max_sum         0       3       7        7      11       11     11      11      11
(INT_MIN)

Ouput = 11

The simple idea of Kadane’s algorithm is to look for all positive contiguous
segments of the array (max_ending_here is used for this).
And keep track of maximum sum contiguous segment among all positive segments
(max_so_far is used for this).
Each time we get a positive-sum compare it with max_so_far and update max_so_far
if it is greater than max_so_far.

Algorithm:
Initialize:
    max_subarr_sum = INT_MIN // max is used
    subarr_sum = 0 // sum is used

Loop for each element of the array
  (a) subarr_sum = subarr_sum + a[i]
  (b) if(max_subarr_sum < max_ending_here)
            max_subarr_sum = subarr_sum
  (c) if(subarr_sum < 0)
            subarr_sum = 0
return max_subarr_sum


*/
int largestSubarrSumKadane(int arr[], int size)
{
    int max_subarr_sum = INT_MIN;
    int subarr_sum = 0;

    // Traverse the array and find the cumulative sum.
    for(int i = 0; i < size; i++)
    {
        subarr_sum += arr[i];

        max_subarr_sum = max(max_subarr_sum, subarr_sum);

        if(subarr_sum < 0)
            subarr_sum = 0;
    }

    return max_subarr_sum;
}



int main(void)
{
    // int arr[] = {-2, -1, -3, -4, 0};
    int arr[] = {1,2,3,-4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest_sum = largestSubarrSum(arr, size);
    cout << largest_sum << endl;

    largest_sum = largestSubarrSumKadane(arr, size);
    cout << largest_sum << endl;

    return 0;
}

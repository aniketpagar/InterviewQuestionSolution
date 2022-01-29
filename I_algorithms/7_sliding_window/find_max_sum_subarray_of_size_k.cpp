/****************************************************************************
File name: find_max_sum_subarray_of_size_k.cpp

Author: babajr
*****************************************************************************/


/*
Given an array of positive numbers and a positive number ‘k’,
find the maximum sum of any contiguous subarray of size ‘k’.

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force. TC = O(n2)

Algo:
--> start from every index of input array and calculate window sum for window size k.
--> keep track of max_sum for all the subarrays.
*/
int find_max_sum_subarr_bf(int arr[], int size, int k)
{
    int max_sum = 0;

    for(int i = 0; i < (size - k + 1); i++)
    {
        int window_sum = 0;

        // get the sum of window with size k.
        for(int j = i; j < (i + k); j++)
        {
            window_sum += arr[j];
        }

        // Get the maximum sum from the subarray sums.
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}


/*
Efficient Approach: SLIDING WINDOW.

Algo:

--> Consider each subarray as a sliding window of size k.
--> Calculate sum of current subarray.
--> In order to calculate the next subarray sum, slide the window forward by one element
    and calculate the sum. In order to do this:
    --> subtract the element going out of the sliding window.
    --> add new element getting in the window.

*/
int find_max_sum_subarr(int arr[], int size, int k)
{
    int window_start = 0;
    int max_sum = 0;
    int window_sum = 0; // to hold each subarray sum.

    for(int window_end = 0; window_end < size; window_end++)
    {
        // get the window sum by adding elements upto size k.
        window_sum += arr[window_end];

        // slide the window once current window sum is calculated.
        if(window_end >= (k - 1))
        {
            // get the max_sum.
            max_sum = max(max_sum, window_sum);
            //remove element going out
            window_sum -= arr[window_start];
            // slide the window
            window_start++;
        }
    }

    return max_sum;
}


int main(int argc, char *argv[])
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    // int arr[] = {};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Subarray Sum: %d\n", find_max_sum_subarr(arr, size, k));
    printf("Maximum Subarray Sum: %d\n", find_max_sum_subarr_bf(arr, size, k));


    return 0;
}

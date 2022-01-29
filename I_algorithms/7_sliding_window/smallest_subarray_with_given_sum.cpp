/*
Given an array of positive numbers and a positive number ‘S’,
find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
Return 0, if no such subarray exists.

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
*/

#include<bits/stdc++.h>
using namespace std;


/*
Efficient Approach: SLIDING WINDOW. (Variable Size Sliding Window)

Algo:
--> Add-up elements from the beginning of the array until their sum becomes
    greater than or equal to ‘S’. This will be our sliding window.
--> Remember the length of this window, as we have to return the smallest length
    of subarray.
--> Keep on adding one element in the window and checking for current window sum >= S.
--> When current window sum >= S, shrink the current window from the begining.
    --> Check if the current window length is the smallest so far, and if so, remember its length.
    --> Subtract the first element of the window from the running sum to shrink the sliding window.
*/
int find_min_subarr_with_given_sum(int arr[], int size, int S)
{
    int window_start = 0;
    int min_len = INT_MAX;
    int window_sum = 0; // to hold each subarray sum.

    for(int window_end = 0; window_end < size; window_end++)
    {
        // get the window sum by adding elements until window_sum >= S.
        window_sum += arr[window_end];

        // shrink the window as small as possible until the window_sum < S.
        while(window_sum >= S)
        {
            // get the min_len.
            min_len = min(min_len, window_end - window_start + 1);
            //remove element going out
            window_sum -= arr[window_start];
            // shrink the window
            window_start++;
        }
    }

    if(min_len == INT_MAX)
        return 0;
    else
        return min_len;
}


int main(int argc, char *argv[])
{
    // int arr[] = {2, 1, 5, 2, 3, 2};
    int arr[] = {};
    int S = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum Subarray length for given Sum: %d\n", find_min_subarr_with_given_sum(arr, size, S));

    return 0;
}

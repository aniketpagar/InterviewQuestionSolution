/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/

Given an integer array arr that is guaranteed to be a mountain, return any i such that
arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

Return the index of peak element in the array.

Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Approach.
API to get the peak of an mountain array.
TC = O(n).
*/
int peak_index_mountain_arr_bf(int arr[], int size)
{
    int index = -1;

    for(int i = 1; i < (size - 1); i++)
    {
        if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
        {
            index = i;
            break;
        }
    }

    return index;
}


/*
API to get the peak of an mountain array.
TC = O(log n).

Idea: Use binary search to search for the peak.

arr[] = 6   7   8   3   2   1   0
        s           m           e
  <- Ascending -> | <-  descending   -->
Algo:

--> if(arr[mid] > arr[mid + 1]) ==> mid is either peak or in the decreasing part of the array
        end = mid // check in left subarray
--> if(arr[mid] < arr[mid + 1]) ==> mid is in the ascending part of the array
        start = mid + 1 // check in right subarray
--> arr[start] ==> at the end start will be pointing to the peak

DRY:
3   4   5   2   1
s       m       e
s   m   e
    ms  e
        mse
*/
int peak_index_mountain_arr(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end) // this condition is very important
    {
        int mid = (start + end) / 2;

        // if arr[mid] is present in the decreasing part of the array
        if(arr[mid] > arr[mid + 1])
        {
            end = mid; // search in the left subarray
        }
        // if arr[mid] is present in the increasing part of the array
        else
        {
            start = mid + 1; // search in the right subarray
        }
    }

    // when the loop ends, start will always be pointing to the peak of the element.
    return start;
}


int main(void)
{
    int arr[] = {0,2,3,4,1};
    // int arr[] = {0,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Index of peak element is : %d\n", peak_index_mountain_arr(arr, size));
    printf("Index of peak element is using brute force : %d\n", peak_index_mountain_arr_bf(arr, size));

    return 0;
}

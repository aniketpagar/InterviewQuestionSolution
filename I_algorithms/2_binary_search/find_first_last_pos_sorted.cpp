/****************************************************************************
File name: find_first_last_pos_sorted.cpp

Author: babajr
*****************************************************************************/


/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value.

If target is not found in the array, print [-1, -1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Approach. TC = O(n)

API to find the first and last position of the target in the given array.
*/
void first_last_position(int arr[], int size, int target)
{
    int start_index = -1;
    int last_index = -1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            if(start_index == -1)
                start_index = i;
            else
                last_index = i;
        }
    }

    if(start_index != -1 && last_index != -1)
        printf("%d\t %d\n", start_index, last_index);
    else
        printf("%d\t %d\n", -1, -1);
}


/*
API to search the element in an array in order to find the first and
last occurance of a target.
TC = O(log n)
*/
int binary_search_element(int arr[], int size, int target, bool is_start_index)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // element is present at the mid.
        if(arr[mid] == target)
        {
            // this is potential answer. But still check for first and last occuance.
            ans = mid;
            if(is_start_index == 1) // for finding first index of target
                end = mid - 1;
            else
                start = mid + 1;
        }
        // element is present in the left subarray. reduce the window of search.
        else if(arr[mid] > target)
            end = mid - 1;
        // element is present in the right subarray. reduce the window of search.
        else
            start = mid + 1;
    }

    return ans;
}


/*
API to get the first and last position of a target.
*/
void first_last_position_efficient(int arr[], int size, int target)
{
    int res[] = {-1, -1}; // array to store the indices of the target.

    // search for the first occurance.
    res[0] = binary_search_element(arr, size, target, 1); // is_start_index = true

    // search for the last occurance.
    res[1] = binary_search_element(arr, size, target, 0); // is_start_index = false

    printf("%d\t %d\n", res[0], res[1]);
}


int main(void)
{
    int arr[] = {5,7,7,8,8,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    first_last_position(arr, size, target);

    first_last_position_efficient(arr, size, target);

    return 0;
}

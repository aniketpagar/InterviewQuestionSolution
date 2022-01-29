/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order
(with distinct values).
Prior to being passed to your function, nums is rotated at an unknown
pivot index k (0 <= k < nums.length) such that the resulting
array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and
become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper function to find the pivot.
*/
int find_pivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 4 cases as mentioned in the algo below.
        if(mid < end && arr[mid] > arr[mid + 1])
            return mid;

        if(mid > start && arr[mid] < arr[mid - 1])
            return mid - 1;

        if(arr[start] > arr[mid]) // pivot will be present on left of mid
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}


/*
Helper function to search the target in sorted array.
*/
int search(int arr[], int target, int start, int end)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // element is present at the mid. Return mid index.
        if(arr[mid] == target)
            return mid;
        // element is present in the left subarray. reduce the window of search.
        else if(arr[mid] > target)
            end = mid - 1;
        // element is present in the right subarray. reduce the window of search.
        else
            start = mid + 1;
    }

    return -1;
}


/*
API to search in rotated sorted array.

Algo:

--> Find PIVOT i.e. maximum element in array.
    --> case1: if(arr[mid] > arr[mid + 1])
                    pivot = mid
    --> case2: if(arr[mid] < arr[mid - 1])
                    pivot = mid - 1
    --> case3: if(arr[start] > arr[mid]) // pivot will be present on left of mid
                    end = mid - 1;
    --> case4: if(arr[start] < arr[mid])
                    start = mid + 1;

--> Search target in left subarray i.e. search(arr, target, 0, pivot).
--> If not found in above step, search in the right subarray i.e. search(arr, target, pivot+1, size - 1).
*/
int search_rotated_arr(int arr[], int size, int target)
{
    // find pivot.
    int pivot = find_pivot(arr, size);

    // if pivot is not found, that means arrays is not rotated.
    if(pivot == -1)
        return search(arr, target, 0, size - 1); // search in the array.

    // if pivot is found, array is rotated.
    // if pivot == target, target is found. return pivot.
    if(arr[pivot] == target)
        return pivot;

    // if above case fails, search in left subarray. If not found, search in the right
    // subarray.
    if(target > arr[pivot])
        return search(arr, target, 0, pivot);
    else
        return search(arr, target, pivot + 1, size - 1);
}


int main(void)
{
    int arr[] = {4,5,6,7,0,1,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int index = search_rotated_arr(arr, size, target);
    if(index != -1)
        printf("Target: %d found at Index: %d\n", target, index);
    else
        printf("Target: %d is not found in an array.\n", target);
    return 0;
}


/****************************************************************************
File name: floor_of_number.cpp

Author: babajr
*****************************************************************************/


/*
Binary Search Algorithm. It can be applied only when the array is SORTED.
Find the floor of a number in a given array. Target value entered is always correct value.

floor of a number = largest element <= number

Input: arr[] = [2,3,5,9,14,16,18], target = 14
Output: 14

Input: arr[] = [2,3,5,9,14,16,18], target = 15
Output: 14
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to find the floor of a number in the given array.
TC = O(log n)
*/
int find_floor(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // element is present at the mid. Return mid index.
        if(arr[mid] == target)
            return arr[mid];
        // element is present in the left subarray. reduce the window of search.
        else if(arr[mid] > target)
            end = mid - 1;
        // element is present in the right subarray. reduce the window of search.
        else
            start = mid + 1;
    }

    return arr[end];
}


int main(void)
{
    int arr[] = {2,3,5,9,14,16,18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    printf("Floor of a target: %d is %d\n", target, find_floor(arr, size, target));

    return 0;
}

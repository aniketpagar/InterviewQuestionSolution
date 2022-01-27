/*
Binary Search Algorithm. It can be applied only when the array is SORTED.
Find the ceiling of a number in a given array. Target value entered is always correct value.

Ceiling of a number = smallest element >= number

Input: arr[] = [2,3,5,9,14,16,18], target = 14
Output: 14

Input: arr[] = [2,3,5,9,14,16,18], target = 15
Output: 16
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to find the ceiling of a number in the given array.
TC = O(log n)
*/
int find_ceiling(int arr[], int size, int target)
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

    return arr[start];
}


int main(void)
{
    int arr[] = {2,3,5,9,14,16,18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 120;

    printf("Ceiling of a target: %d is %d\n", target, find_ceiling(arr, size, target));

    return 0;
}

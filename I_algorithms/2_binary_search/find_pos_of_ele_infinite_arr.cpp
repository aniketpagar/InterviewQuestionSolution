/*
Find the position of element in a sorted array of
Infinite numbers.

Array with infinite numbers ==> means array length is not known.

Input: arr = [2,3,5,6,7,15.....], target = 15
Output: 5
*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper function to search the target in the given window.
*/
int search(int arr[], int target, int start, int end)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(target == arr[mid])
            return mid; // target found return index of target i.e. mid.
        else if(target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // if target not found we are returning -1.
}


/*
Efficient Approach. TC = O(log n)
API to find the position of element in sorted infinite array.
*/
int find_position_infinite_arr_bs(int arr[], int target)
{
    // start with smallest posible range / window i.e. 2.
    // if target is not found in that range, double the size of window
    // and go on doing that until target is found.
    int start = 0;
    int end = 1;

    // array is sorted, so condition for possibility
    // of target to be not in range
    while(target > arr[end])
    {
        int new_start = end + 1; // starting point of new window.
        // as said above double the size of window.
        end = end + ((end - start + 1) * 2);
        start = new_start;
    }

    // if above while condition fails, means target may be present in the window.
    return search(arr, target, start, end);
}

int main(void)
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int index = find_position_infinite_arr_bs(arr, target);
    if(index != -1)
        printf("Target: %d found at Index: %d\n", target, index);
    else
        printf("Target: %d is not found in an array.\n", target);
    return 0;
}

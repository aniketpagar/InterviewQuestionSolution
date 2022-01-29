/*
Binary Search Algorithm. It can be applied only when the array is SORTED.
Here we will see logic for order agnostic binary search.
That means, one API can be used to search in both increasing as well as decreasing arrays.
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to search element in an array using order agnostic binary search.
TC = O(log n)
*/
int order_agnostic_binary_search(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    bool is_ascending = arr[start] < arr[end]; // True: array is in increasing/ascending.

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // element is present at the mid. Return mid index.
        if(arr[mid] == target)
            return mid;

        if(is_ascending == 1) // array is increasing array
        {
            // element is present in the left subarray. reduce the window of search.
            if(arr[mid] > target)
                end = mid - 1;
            // element is present in the right subarray. reduce the window of search.
            else
                start = mid + 1;
        }
        else
        {
            if(arr[mid] > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1; // If element is not found in the array we will return -1.
}


int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8};
    // int arr[] = {4,5,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int index = order_agnostic_binary_search(arr, size, target);
    if(index != -1)
        printf("Target: %d found at Index: %d\n", target, index);
    else
        printf("Target: %d is not found in an array.\n", target);
    return 0;
}

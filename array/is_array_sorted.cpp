#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
API to check if the given array is sorted or not.
*/
bool is_sorted_recursive(int arr[], int size, int index)
{
    // base case
    if(size < 0 || index == size)
        return true;

    return (arr[index] <= arr[index + 1]) && (is_sorted_recursive(arr, size, index + 1));
}


/*
Brute Force: TC = O(n2)
API to check if array is sorted or not.
*/
bool is_sorted(int arr[], int size)
{
    // traverse the array and check whether current element is < / > next element.
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j])
                return false; // array is not sorted
        }
    }

    return true; // array is sorted
}


/*
Efficient Approach: TC = O(n)
API to check if given array is sorted or not.
*/
bool is_sorted_eff(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < arr[i - 1])
            return false;
    }

    return true;
}


int main(void)
{
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", is_sorted_recursive(arr, size - 1, 0)); // 1 ==> sorted, 0 ==> not sorted
    printf("%d\n", is_sorted(arr, size)); // 1 ==> sorted, 0 ==> not sorted
    printf("%d\n", is_sorted_eff(arr, size)); // 1 ==> sorted, 0 ==> not sorted

    return 0;
}

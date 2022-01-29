/****************************************************************************
File name: remove_all_duplicates.cpp

Author: babajr
*****************************************************************************/


/*
Given an array of sorted numbers, remove all duplicates from it.
After removing the duplicates in-place return the new length of the array.

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be
             [2, 3, 6, 9].

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force. Using Extra Array to store unique elements.
Algo:

--> Create an auxiliary array aux_arr[] to store unique elements.
--> Traverse input array and one by one copy unique elements of arr[] to aux_arr[].
    Also keep track of count of unique elements. Let this count be unique_ele.
--> Copy unique_ele elements from aux_arr[] to arr[] and return unique_ele which
    will be new array length.
*/
int remove_duplicates_bf(int arr[], int size)
{
    // in case array is empty or contain 1 element.
    if(size == 0 || size == 1)
        return size;

    // temporary array to store the unique elements.
    int aux_arr[size];
    int unique_ele = 0; // to keep track of unique elements.

    for(int i = 0; i < size - 1; i++)
    {
        // if current ele is not same as next element then store it in temporary array.
        if(arr[i] != arr[i+1])
        {
            aux_arr[unique_ele] = arr[i];
            unique_ele++;
        }
    }

    // store the last element as it is not stored previously.
    aux_arr[unique_ele++] = arr[size - 1];

    // update the original array with the updated values.
    for(int j = 0; j < unique_ele; j++)
        arr[j] = aux_arr[j];

    return unique_ele;
}


/*
Two Pointer Approach.

Algo:
--> As input array is sorted, one way to do this is to shift the elements left whenever
    we encounter duplicates.
--> We will keep one pointer for iterating the array and one pointer for placing the
    next non-duplicate number.
    i.e. iterate the array and whenever we see a non-duplicate number we move it
    next to the last non-duplicate number we’ve seen
*/
int remove_duplicates(int arr[], int size)
{
    int next_duplicate = 1; // index of next non duplicate element.

    // traverse the array from 1st index.
    for(int i = 1; i < size; i++)
    {
        if(arr[next_duplicate - 1] != arr[i])
        {
            arr[next_duplicate] = arr[i];
            next_duplicate++;
        }
    }

    return next_duplicate; // new array length
}


/*
Brute Force approach. Simple way.

Just maintain a separate index for same array as maintained for different array in
brute force approch.
*/
int remove_duplicates_simple(int arr[], int size)
{
    // in case array is empty or contain 1 element.
    if(size == 0 || size == 1)
        return size;

    int unique_ele = 0; // to keep track of next unique element.

    for(int i = 0; i < size - 1; i++)
    {
        // if current ele is not same as next element then replace it with the
        // unique element.
        if(arr[i] != arr[i+1])
        {
            arr[unique_ele] = arr[i];
            unique_ele++;
        }
    }

    // store the last element as it is not stored previously.
    arr[unique_ele++] = arr[size - 1];

    return unique_ele;

}


int main(void)
{
    int arr[] = {2, 3, 3, 3, 6, 9, 9};
    // int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // printf("Array new length: %d\n", remove_duplicates_bf(arr, size));
    printf("Array new length: %d\n", remove_duplicates(arr, size));
    printf("Array new length: %d\n", remove_duplicates_simple(arr, size));

    return 0;
}

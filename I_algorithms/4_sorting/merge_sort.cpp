/****************************************************************************
File name: merge_sort.cpp

Author: babajr
*****************************************************************************/


#include <iostream>
#include <cassert>
using namespace std;


/*
Helper API to swap the numbers.
*/
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


/*
API to Merge Arrays left and right into arr.
left_arr_size = number of elements in left
right_arr_size = number of elements in right.
*/
void merge(int *arr, int *left, int *right,  int left_arr_size, int right_arr_size)
{
    int i = 0, j = 0, k = 0;

    // i - to mark the index of left aubarray (left)
    // j - to mark the index of right sub-raay (right)
    // k - to mark the index of merged subarray (arr)

    // merge the left and right subarray values in sorted way in arr.
    while(i < left_arr_size && j < right_arr_size)
    {
        if(left[i]  < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // copy the remaining elements from left and right array to arr.
    while(i < left_arr_size)
        arr[k++] = left[i++];

    while(j < right_arr_size)
        arr[k++] = right[j++];
}


/*
API to sort the array using merge sort algorithm.

Merge Sort => recursive sort. TC = O(n logn)
*/
void merge_sort(int arr[], int size)
{
    int *left = NULL;
    int *right = NULL;
    int i;

    // array contains only one element. i.e. array is sorted.
    if(size < 2) // base case
        return;

    int mid = size / 2; // get the mid index.

    // create left and right subarrays.
    // mid elements (from index 0 till mid-1) should be part of
    // left sub-array.
    // and (n-mid) elements (from mid to n-1) will be part of right
    // sub-array.
    left = (int*)malloc(mid * sizeof(int));
    right = (int*)malloc((size - mid) * sizeof(int));

    // creating left subarray
    for(i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    // creating right subarray
    for(i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);  // sorting the left subarray
    merge_sort(right, size - mid);  // sorting the right subarray

    // Merging left and right subarrays into array as sorted list.
    merge(arr, left, right, mid, size - mid);

    // free the unused memory.
    free(left);
    free(right);
}


/*
Helper API to print the array.
*/
void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


int main(void)
{
    int arr[] = {1,4,5,2,3,6};
    // int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    print_arr(arr, size);

    merge_sort(arr, size);
    printf("Sorted Array: \n");
    print_arr(arr, size);
}

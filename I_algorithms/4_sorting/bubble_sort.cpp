/****************************************************************************
File name: bubble_sort.cpp

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
API to sort the array using bubble sort algorithm.

Idea is to take the larger element to the end by repeatedly
swapping the adjacent elements.
*/
void bubble_sort(int arr[], int size)
{
    for(int times = 0; times < size - 1; times++)
    {
        int flag = 0; // to check if array is already sorted or not.
                      // 0 ==> array is already sorted

        for(int i = 0; i < (size - times - 1); i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                flag = 1; // array is not already sorted
            }
        }

        if(flag == 0) // array is already sorted, no need to
            break;    // go for another iteration.
    }
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
    // int arr[] = {1,4,5,2,3,6};
    int arr[] = {1,2,3,4,5,7,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    print_arr(arr, size);

    bubble_sort(arr, size);
    printf("Sorted Array: \n");
    print_arr(arr, size);
}

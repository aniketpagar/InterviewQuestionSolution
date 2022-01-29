/*
Given an array containing 0s, 1s and 2s, sort the array in-place.
You should treat numbers of the array as objects,
hence, we can’t count 0s, 1s, and 2s to recreate the array.

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]
*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper API to swap the two elements in an array.
*/
void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


/*
Two Pointer Approach.

Algo:
--> Use two pointers i.e. low and high. low is pointing to first and high is pointing
    to last element.
--> move all zeros to left of low and all twos after high.
--> all ones will remain between low and high.
*/
void sort_dutch_national_flag(int arr[], int size)
{
    // 0    0   0   1   1   1   1   2   2   2
    //              low        high
    // all elements < low are 0.
    // all elements > high are 2.
    // all elements from >= low to i are 1.
    int low = 0, high = size - 1;

    // traverse the array.
    int i = 0;
    while(i <= high)
    {
        if(arr[i] == 0) // move 0's to left of low.
        {
            swap(arr, i, low);
            i++;
            low++;
        }
        else if(arr[i] == 1)
        {
            i++;
        }
        else // if(arr[i] == 2)
        {
            swap(arr, i, high); // move 2's to right of high.
            high--;
        }
    }
}


/*
Helper API to print the array.
*/
void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}


int main(void)
{
    int arr[] = {1, 2, 2, 0, 0, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array\n");
    print_array(arr, size);

    sort_dutch_national_flag(arr, size);
    print_array(arr, size);

    return 0;
}

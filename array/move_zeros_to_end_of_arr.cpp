/*
Move zeros to the end of the array.

Inpuy: arr = {12, 10, 0, 1, 5, 0, 6}
Output: arr = {12, 10, 1, 5, 6, 0, 0}
*/

#include <bits/stdc++.h>
using namespace std;


/*
Helper API to swap the array elements.
*/
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


/*
Brute Force Approach.
TC: O (n2)

--> traverse the array. if 0 is found, replace it with next non zero element.
--> 2 for loops are required. one for traversing the array and other
    for finding out next non zero element.
*/
void move_zeros_bf(int arr[], int size)
{
    // traverse the array and check for 0's.
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            // once zero is found, search for next non zero element.
            // swap the 0 with next non zero element.
            for(int j = i + 1; j < size; j++)
            {
                if(arr[j] != 0)
                    swap(&arr[i], &arr[j]);
            }
        }
    }
}


/*
Efficient Approach.
TC = O(n)

--> while traversing the array, keep the count of non zero elements.
--> swap the zeros with next non zero elements.

                            i
        10  12  1   5   0   0
                        in
*/
void move_zeros_eff(int arr[], int size)
{
    int index = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] != 0)
        {
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
}


/*
Helper API to print the elements of the array.
*/
void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\n");
}


int main(void)
{
    int arr[] = {12, 10, 0, 1, 5, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    print_array(arr, size);

    // move_zeros_bf(arr, size);
    move_zeros_eff(arr, size);
    printf("Modified Array: \n");
    print_array(arr, size);

    return 0;
}

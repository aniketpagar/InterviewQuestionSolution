
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


/*
API to sort array of 0's and 1's.

Algo:
--> Count the number of 0's first i.e. count_zeros.
--> So number of 1's will be, count_ones = size - count_zeros.
--> Now update the array by fillng first count_zeros positions with 0 and
    remaining positions with 1.
*/
void sort_array(int arr[], int size)
{
    int count_zeros = 0;
    int count_ones = 0;
    int i;

    for(i = 0; i < size; i++)
    {
        if(arr[i] == 0)
            count_zeros++;
    }

    count_ones = size - count_zeros;

    // insert the 0's first for first count_zeros position
    for(i = 0; i < count_zeros; i++)
        arr[i] = 0;

    // insert the 1's in remaining array
    for(i = count_zeros; i < size; i++)
        arr[i] = 1;
}


/*
Helper API to print the array.
*/
void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}


int main(void)
{
    int arr[] = {1,0,1,0,0,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array\n");
    print_array(arr, size);

    sort_array(arr, size);
    printf("Sorted Array\n");
    print_array(arr, size);


    return 0;
}

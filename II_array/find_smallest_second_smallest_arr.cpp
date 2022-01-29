/****************************************************************************
File name: find_smallest_second_smallest_arr.cpp

Author: babajr
*****************************************************************************/


/*
Program to get the smallest and second smallest element
in the array.

Input: arr = [4,1,3,10,12,1]
Output: 12, 10

*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the smallest elemenet and second smallest element in the array.

Algo:
--> BRUTE FORCE
    --> sort the array in the ascending order
    --> first and second element are the smallest and second smallest.

--> Efficient Solution
    --> first = second = MAX_VAL
    --> traverse the array,
        if(arr[i] < first), update second and first
        else if(arr[i] < second), update second
*/
void find_smallest_second_smallest(int arr[], int size)
{
    int first = INT_MAX;
    int second = INT_MAX;

    if(size < 2) // array must contain atleast 2 elements.
        return;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
        // second condition for duplicate elements
        else if(arr[i] < second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    if(second == INT_MAX) // array may contain same element multiple times
        printf("Second Smallest element not found\n");
    else
        printf("Smallest : %d and Second Smallest : %d\n", first, second);
}


int main(void)
{
    int arr[] = {4,1,3,10,12,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_smallest_second_smallest(arr, size);

    return 0;
}

/****************************************************************************
File name: find_single_duplicate_ele.cpp

Author: babajr
*****************************************************************************/


/*
https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each
integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper API to swap the elements of an array.
*/
void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}


/*
API to display the contents of the array.
*/
void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}


/*
API to find the single duplicate element in an array with elements
in range (1, N).

Algo:

--> Use cyclic sort. During sorting check if duplicate element occur at
    particular index. If yes, return that element.

*/
int find_single_duplicate_element(int arr[], int size)
{
    int index = 0;

    // use cyclic sort on the array.
    while(index < size)
    {
        // check if current element is present at correct index.
        if(arr[index] != index + 1) // element is not present at correct index
        {
            // get the correct index of current element.
            int correct = arr[index] - 1; // if range(1, N)

            // check if arr[i] (current element) is present at correct index.
            if(arr[index] != arr[correct])
            {
                // current element is not present at correct index,
                // swap it with the element at correct index.
                swap(arr, index, correct);
            }
            else
                return arr[index]; // duplicate found
        }
        else
            index++;
    }


    return -1; // no duplicate found
}


int main(void)
{
    int arr[] = {1,3,4,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print_array(arr, size);
    printf("%d\n", find_single_duplicate_element(arr, size));
    // print_array(arr, size);

    return 0;
}


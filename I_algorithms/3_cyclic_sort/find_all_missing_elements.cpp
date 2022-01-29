/****************************************************************************
File name: find_all_missing_elements.cpp

Author: babajr
*****************************************************************************/


/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Given an array nums of n integers where nums[i] is in the range [1, n],
return an array of all the integers in the range [1, n]
that do not appear in nums.

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Input: nums = [1,1]
Output: [2]

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
API to find the all missing elements in an array with elements
in range (1, N).

*/
void find_all_missing_element(int arr[], int size)
{
    int index = 0;

    // use cyclic sort on the array.
    while(index < size)
    {
        // get the correct index of current element.
        // int correct = arr[index]; // if range(0, N)
        int correct = arr[index] - 1; // if range(1, N)

        // check if arr[i] (current element) is present at correct index.
        if(arr[index] != arr[correct])
        {
            // current element is not present at correct index,
            // swap it with the element at correct index.
            swap(arr, index, correct);
        }
        else // if current element is present at correct index
             // just check for next element.
            index++;
    }

    // Search for missing element in the cyclically sorted array.
    for(int i = 0; i <= size; i++)
    {
        if(arr[i] != i + 1)
            printf("%d\t", i + 1);
    }
}


int main(void)
{
    int arr[] = {4,3,2,7,2,3,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print_array(arr, size);
    find_all_missing_element(arr, size);
    // print_array(arr, size);

    return 0;
}

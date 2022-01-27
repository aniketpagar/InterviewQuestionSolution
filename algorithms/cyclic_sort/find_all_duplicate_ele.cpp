/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appears once or twice,
return an array of all the integers that appears twice.

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

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
API to find the all duplicate elements in an array with elements
in range (1, N).

*/
void find_all_duplicate_elements(int arr[], int size)
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

    // Search for duplicate elements in the cyclically sorted array.
    for(int i = 0; i < size; i++)
    {
        if(arr[i] != i + 1)
            printf("%d\t", arr[i]);
    }
}


int main(void)
{
    int arr[] = {4,3,2,7,8,2,3,1};
    // int arr[] = {4,0,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_all_duplicate_elements(arr, size);

    return 0;
}

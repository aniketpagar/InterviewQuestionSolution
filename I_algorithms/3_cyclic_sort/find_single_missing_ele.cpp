/*
https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all
numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers
are in the range [0,1]. 1 is the missing number
in the range since it does not appear in nums.

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
API to find the single missing element in an array with elements
in range (0, N).

Idea is to use cyclic sort and check for index in a sorted array
which do not contain correct value.

Two possible cases:
case 1: Missing element is other that the N.
        Ex. arr = [4,0,2,1] (i.e. N = 4)
    --> cyclic sort the array first
idx     0   1   2   3
arr     4   0   2   1
        i
        --> correct index for 4 = 4. Index 4 is out of range, so ignore.
            increment i.
        4   0   2   1
            i
        --> correct index of 0 = 0. swap 0 with correct index.
        0   4   2   1
            i
        --> correct index of 4 = 4, which is out of range, so ignore.
            increment i.
        0   4   2   1
                i
        --> correct index of 2 = 2. increment i.
        0   4   2   1
                    i
        --> correct index of 1 = 1. swap 1 with value at correct index.
        0   1   2   4 ==> sorted array.

case 2: Element missing is the N.
    1   0   3   2

    sorted array = 0   1   2   3
    Missing element = N.

    --> Search in the sorted array for value which is not at correct index.
        The missing element = index of incorrect element.
        0   1   2   4
Index   0   1   2   3
        ANS = 3
*/
int find_single_missing_element(int arr[], int size)
{
    int index = 0;

    // use cyclic sort on the array.
    while(index < size)
    {
        // get the correct index of current element.
        // int correct = arr[index]; // if range(0, N)
        int correct = arr[index] - 1; // if range(1, N)

        // check if arr[i] (current element) is present at correct index.
        if(arr[index] < size && arr[index] != arr[correct])
        {
            // current element is not present at correct index,
            // swap it with the element at correct index.
            swap(arr, index, correct);
        }
        else // if current element is present at correct index
             // just check for next element.
            index++;
    }

    // case 1: Search for missing element if it is other than N.
    for(int i = 0; i < size; i++)
    {
        if(arr[i] != i + 1) // range(1, N)
        // if(arr[i] != i) // mismatch between index and its element. range(0, N)
            // return i; // index of wrong element will be the missing element.
            return i + 1; // range(1, N)
    }

    // case 2: If missing number is N.
    return size + 1; // range(1, N)
    // return size; // range(0, N)
}


int main(void)
{
    // int arr[] = {0};
    int arr[] = {5,4,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print_array(arr, size);
    printf("%d\n", find_single_missing_element(arr, size));
    // print_array(arr, size);

    return 0;
}

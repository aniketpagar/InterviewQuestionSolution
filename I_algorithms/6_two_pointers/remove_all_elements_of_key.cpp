/****************************************************************************
File name: remove_all_elements_of_key.cpp

Author: babajr
*****************************************************************************/


/*
Unsorted array of numbers is given and a target ‘key’, remove all instances of ‘key’
in-place and return the new length of the array.

Input: [3, 2, 3, 6, 3, 10, 9, 3], Key = 3
Output: 4
Explanation: The first four elements after removing every 'Key' will be [2, 6, 10, 9].

Input: [2, 11, 2, 2, 1], Key = 2
Output: 2
Explanation: The first two elements after removing every 'Key' will be [11, 1].
*/

#include<bits/stdc++.h>
using namespace std;


/*
Two Pointer Approach.

Algo:
--> Idea is to shift numbers left upon encountering the ‘key’.
--> As input array is sorted, one way to do this is to shift the elements left whenever
    we encounter element == key.
--> We will keep one pointer for iterating the array and one pointer for placing the
    next element not equal to key.
    i.e. iterate the array and whenever we see a arr[next_ele] != key we move it
    next to the last next_element number we’ve seen.
*/
int remove_elements_equal_to_key(int arr[], int size, int key)
{
    int next_ele = 0; // index of next element which is not key.

    // traverse the array.
    for(int i = 0; i < size; i++)
    {
        if(arr[next_ele] != key)
        {
            arr[next_ele] = arr[i];
            next_ele++;
        }
    }

    return next_ele; // new array length
}


int main(void)
{
    int arr[] = {3, 2, 3, 6, 3, 10, 9, 3};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array new length: %d\n", remove_elements_equal_to_key(arr, size, key));

    return 0;
}

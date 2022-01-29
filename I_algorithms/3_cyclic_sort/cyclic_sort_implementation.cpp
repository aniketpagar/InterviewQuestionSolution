/****************************************************************************
File name: cyclic_sort_implementation.cpp

Author: babajr
*****************************************************************************/


/*
Cyclic Sort Algorithm.

Note: Applicable only when elements in the array are in range (0, N) or
(1, N).
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
API to implement the cyclic sort algorithm.
TC = O(n)

Idea is to check if element is present at correct index, if not the
swap element with element at correct index.

For range (0, N) ==> correct_index = index of current element.
For range (1, N) ==> correct_index = index of current element - 1.

This algorithm, takes care of duplicate elements also.

i
0   1   2   3   4       ==> range(1, N)
3   5   1   2   4

--> 3 is not present at correct index (correct = 3-1 = 2).
    swap arr[0] with arr[correct].
    1   5   3   2   4
    i
--> 1 is at correct index. increment i.
    1   5   3   2   4
        i
--> 5 is not at correct index. correct = 5 - 1 = 4. swap arr[1] with arr[correct].
    1   4   3   2   5
        i
--> 4 is also not at correct index. correct = 4 - 1 = 3.
    1   2   3   4   5
        i
--> 2, 3, 4, 5 are correct indices. checked this by incrementing i by one.
*/
int cyclic_sort(int arr[], int size)
{
    int index = 0;

    while(index < size)
    {
        // get the correct index of current element.
        int correct = arr[index] - 1;

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
}


int main(void)
{
    int arr[] = {3,2,1,2,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    cyclic_sort(arr, size);
    print_array(arr, size);

    return 0;
}

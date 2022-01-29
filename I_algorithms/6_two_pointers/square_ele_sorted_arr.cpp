/*
Given a sorted array, create a new array containing squares of all the number of the input
array in the sorted order.

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
*/

#include<bits/stdc++.h>
using namespace std;


/*
Two Pointer Approach.

Algo:
--> Elements at both the ends can give us the largest square, use two pointers starting at
    both the ends of the input array.
--> At any step, whichever pointer gives us the bigger square we add it to the result
    array and move to the next/previous number according to the pointer.
*/
int *squared_arr(int arr[], int size)
{
    // result array to store the square of the elements.
    int *result = (int *) calloc(size, sizeof(int));

    int highest_square_idx = size - 1; // index use to put the sqaure values in the order.

    // pointers starting from the two ends.
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int left_sq = arr[left] * arr[left];
        int right_sq = arr[right] * arr[right];

        if(left_sq > right_sq)
        {
            result[highest_square_idx] = left_sq;
            highest_square_idx--;
            left++;
        }
        else
        {
            result[highest_square_idx] = right_sq;
            highest_square_idx--;
            right--;
        }
    }

    return result;
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
    int arr[] = {-2, -1, 0, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array\n");
    print_array(arr, size);

    int *res = squared_arr(arr, size);
    print_array(res, size);

    return 0;
}

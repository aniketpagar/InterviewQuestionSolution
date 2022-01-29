/****************************************************************************
File name: pair_sum_in_sorted_arr.cpp

Author: babajr
*****************************************************************************/


/*
In patterns where we  deal with sorted arrays (or LinkedLists) and need to find a
set of elements that fulfill certain constraints, the Two Pointers approach becomes
quite useful.

Given an array of sorted numbers and a target sum,
find a pair in the array whose sum is equal to the given target.

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2 + 4 = 6
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Approach.
TC: O(n2)
SC: O(1)
*/
pair<int, int> find_pair_sum_bf(int arr[], int size, int target_sum)
{
    /*
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] + arr[j] == target_sum) // this may cause overflow
            {
                return make_pair(i, j);
            }
        }
    }
    */

    // To avoid overflow of arr[i] + arr[j], using below logic.
    for(int i = 0; i < size-1; i++)
    {
        int num_to_find = target_sum - arr[i];
        for(int j = i + 1; j < size; j++)
        {
            if(num_to_find == arr[j])
                return make_pair(i, j);
        }
    }

    return make_pair(-1, -1);
}


/*
Two Pointer Approach.

Algo:
--> start with one pointer (left) pointing to the beginning of the array and another (right)
    pointing at the end. At every step, we will see if the numbers pointed by the
    two pointers add up to the target sum.
    If they do, we have found our pair; otherwise, we will do one of two things:
    --> if target_sum > (arr[left] + arr[right]), decrement the right pointer.
    --> if target_sum < arr[left] + arr[right]), increment the left pointer.
*/
pair<int, int> find_pair_sum(int arr[], int size, int target_sum)
{
    // two pointers, one starting from the start and other starting from the end.
    int left = 0;
    int right = size - 1;

    while(left < right)
    {
        int curr_sum = arr[left] + arr[right];

        if(curr_sum == target_sum) // pair is found
            return make_pair(left, right); // returning the indices of the pair.
        else if(curr_sum < target_sum) // need pair with smaller sum
            left++;
        else // need pair with greater sum
            right--;
    }

    return make_pair(-1, -1); // If target_sum not found return (-1, -1).
}


int main(void)
{
    int arr[] = {1, 2, 3, 4, 6};
    int target_sum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    auto pair_of_indices = find_pair_sum(arr, size, target_sum);
    printf("Pair with target sum: [ %d , %d ]\n", pair_of_indices.first, pair_of_indices.second);

    auto pair_of_indices1 = find_pair_sum_bf(arr, size, target_sum);
    printf("Pair with target sum: [ %d , %d ]\n", pair_of_indices1.first, pair_of_indices1.second);

    return 0;
}

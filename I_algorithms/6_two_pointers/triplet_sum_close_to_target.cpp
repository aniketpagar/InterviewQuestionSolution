/*
Given an array of unsorted numbers and a target number, find a triplet in the array
whose sum is as close to the target number as possible, return the sum of the triplet.
If there are more than one such triplet,
return the sum of the triplet with the smallest sum.

Input: [-2, 0, 1, 2], target = 2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.

Input: [-3, -1, 1, 2], target = 1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
*/

#include<bits/stdc++.h>
using namespace std;


/*
Two Pointer Approach.

Algo:
--> As input array is not sorted, so first sort it.
--> Iterate through the sorted array and take one element at a time i.e. X.
--> At every step, we will save the difference between the triplet and the target number,
    so that in the end, we can return the triplet with the closest sum.
*/
int triplet_sum_close_to_target(int arr[], int size, int target)
{
    int smallest_diff = INT_MAX;

    // first sort the array.
    sort(arr, arr + size);

    // traverse the array.
    for(int i = 0; i < size - 2; i++)
    {
        int left = i + 1; // left pointer
        int right = size - 1; // right pointer

        while(left < right)
        {
            // comparing the sum of triplets to the target may cause overflow.
            // so, we will try to find the target difference.
            // int current_sum = arr[i] + arr[left] + arr[right];
            // int target_diff = target - current_sum;
            int target_diff = target - arr[i] - arr[left] - arr[right];

            if(target_diff == 0)
            {
                // found the triplet with exact sum equal to target
                // return the sum of triplet.
                return (target - target_diff);
            }

            // update the smallest difference with closest difference.
            if(abs(smallest_diff) > abs(target_diff))
                smallest_diff = target_diff;

            if(target_diff > 0)
                left++; // we need bigger sum.
            else
                right--; // we need smaller sum.
        }
    }

    return target - smallest_diff;
}


int main(void)
{
    int arr[] = {-2, 0, 1, 2};
    // int arr[] = {-3, -1, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    printf("Sum of the triple: %d\n", triplet_sum_close_to_target(arr, size, target));

    return 0;
}

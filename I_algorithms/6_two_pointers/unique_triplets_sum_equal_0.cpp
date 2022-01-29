/****************************************************************************
File name: unique_triplets_sum_equal_0.cpp

Author: babajr
*****************************************************************************/


/*
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper API to search for pair equal to sum.
*/
void find_pair(int arr[], int size, int target_sum, int left, vector<vector<int>> &triplets)
{
    int right = size - 1;

    while(left < right)
    {
        int current_sum = arr[left] + arr[right];

        // find the pair.
        if(current_sum == target_sum)
        {
            triplets.push_back({-target_sum, arr[left], arr[right]});

            left++;
            right--;

            //skip same element to avoid duplicate triplets.
            while(left < right && arr[left] == arr[left - 1])
                left++;
            while(left < right && arr[right] == arr[right + 1])
                right--;
        }
        else if(target_sum > current_sum)
            left++; // need pair with bigger sum.
        else
            right--; // need pair with smaller sum.
    }
}


/*
Two Pointer Approach.

Algo:
--> As input array is not sorted, so first sort it.
--> Iterate through the sorted array and take one element at a time i.e. X.
--> Assume we are at X, so we need to find Y and Z such that X + Y + Z = 0.
    At this stage, our problem translates into finding a pair whose sum is equal to
    -X. i.e. Y + Z = -X.
--> We need to find unique triplets, to handle this skip any duplicate number.
*/
vector<vector<int>> search_triplets(int arr[], int size)
{
    // result array to store the triplets.
    vector<vector<int>>  triplets;

    // first sort the array using C++ sort API.
    sort(arr, arr+size);

    // traverse the array. while traversing if duplicate elements occur, skip them.
    for(int i = 0; i < size - 2; i++) // size - 2 used as we are finding triplet.
    {
        if(i > 0 && arr[i] == arr[i - 1])
            continue; // skip same element to avoid duplicate triplets.

        // search for other two elements such that Y + Z = -X.
        find_pair(arr, size, -arr[i], i + 1, triplets);
    }

    // return the result.
    return triplets;
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
    // int arr[] = {-3, 0, 1, 2, -1, 1, -2};
    int arr[] = {-5, 2, -1, -2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array\n");
    print_array(arr, size);

    auto res = search_triplets(arr, size);

    for(auto vect : res)
    {
        printf("[");

        for(auto ele : vect)
            printf("%d ", ele);

        printf("]");
    }

    return 0;
}

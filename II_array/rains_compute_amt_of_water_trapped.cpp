/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1, compute how much water it is
able to trap after raining.

Input: arr[]   = {2, 0, 2}
Output: 2

Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
*/


#include<bits/stdc++.h>
using namespace std;


/*
Brute Force. TC = O(n2)
Idea is to traverse the array from start to end and for each element get the
Max on left and right side.
Amount of water stored at i = water_i = min(leftMax, rightMax) - arr[i]
Total Water trapped, water_trapped = water_trapped + water_i
*/
int maxWater(int arr[], int size)
{
    int total_water_trapped = 0;

    for(int i = 1; i < size - 1; i++) // Ignore 0th and last element as, they can not trap water.
    {
        // get maximum element on left of i.
        int leftMax = arr[i];
        for(int j = 0; j < i; j++)
            leftMax = max(leftMax, arr[j]);

        // get maximum element on right of i.
        int rightMax = arr[i];
        for(int j = i+1; j < size; j++)
            rightMax = max(rightMax, arr[j]);

        int water_trpped_i = min(leftMax, rightMax) - arr[i];

        total_water_trapped += water_trpped_i;
    }

    return total_water_trapped;
}


/*
Approach 2: We will pre compute the highest bars on left and right of every bar.
TC = O(n).
Algo:
--> We will have two arrays i.e. left[] and right[], to store pre computed values.
--> First fill left array --> left[i] = max(left[i-1], left[i])
--> Fill right array --> right[i] = max(right[i-1], right[i])
--> Water at each bar water_i--> min(left[i], right[i]) - arr[i]
--> total water trapped --> water_trapped = water_trapped + water_i
*/
int maxWaterOptimised(int arr[], int size)
{
    int total_water_trapped = 0;
    int left[12] = {0}; // We can have MACRO instead of hard coded value.
    int right[12] = {0};

    // Fill the left array.
    left[0] = arr[0];
    for(int i = 1; i < size; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }

    // Fill the right array.
    right[0] = arr[size - 1];
    for(int i = size - 2; i >= 0; i--)
    {
        right[i] = max(right[i+1], arr[i]);
    }

    for(int j = 1; j < size - 1; j++)
    {
        int water_trpped_j = min(left[j], right[j]) - arr[j];
        total_water_trapped += water_trpped_j;
    }

    return total_water_trapped;
}


int main(void)
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int arr[] = {2, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Total water trapped: " << maxWater(arr, size) << endl;
    cout << "Total water trapped: " << maxWaterOptimised(arr, size) << endl;

    return 0;
}

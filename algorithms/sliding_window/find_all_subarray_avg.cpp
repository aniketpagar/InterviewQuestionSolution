/*
Given an array, find the average of all contiguous subarrays of size ‘K’ in it.

Input: Array: [1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
Output: [2.2, 2.8, 2.4, 3.6, 2.8]
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Forec. Tc = O(n2)

calculate the sum of every k-element contiguous subarray of the given array and
divide the sum by ‘k’ to find the average.
*/
double *subarrays_avg(int arr[], int size, int k)
{
    double *avg = (double *)calloc((size - k + 1), sizeof(double));

    for(int i = 0; i < (size - k + 1); i++)
    {
        // find sum of next k elements.
        double sum = 0;

        for(int j = i; j < (i + k); j++)
            sum += arr[j];

        avg[i] = sum / k;
    }

    return avg;
}


/*
Efficient Approach. SLIDING WINDOW.

Algo:
--> visualize each contiguous subarray as a sliding window of ‘5’ elements.
--> This means that when we move on to the next subarray, we will slide the window by one
    element. So, to reuse the sum from the previous subarray, we will subtract the
    element going out of the window and add the element now being included in the
    sliding window.
*/
double *subarrays_avg_sliding_window(int arr[], int size, int k)
{
    double *avg = (double *)calloc(sizeof(double), (size - k + 1));
    double window_sum = 0;
    int window_start = 0;

    for(int window_end = 0; window_end < size; window_end++)
    {
        // add the current element to the window sum.
        window_sum += arr[window_end];

        // slide the window, once the first subarray sum is calculated.
        if(window_end >= (k - 1))
        {
            // calculate the avg of window.
            avg[window_start] = window_sum / k;

            // printf("%lf\t", avg[window_start]);

            // remove the element which is going out.
            window_sum -= arr[window_start];

            // slide the window ahead.
            window_start++;
        }
    }

    return avg;
}


int main(void)
{
    int arr[] = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    double *res = (double *)calloc(sizeof(double), (size - k + 1));
    // res = subarrays_avg(arr, size, k);
    res = subarrays_avg_sliding_window(arr, size, k);

    for(int i = 0; i < 5; i++)
        printf("%lf\t", res[i]);

    return 0;
}

/*
Array of non negative integer is given as an input. Find the subarray such that its
sum is equal to given target. print the start and last index of all possible subarrays

Input: {1,3,2,1,4,1,3,2,1,1,2}
Output: (2,5), (4,6) (5,9)

Explaination:
0   1   2   3   4   5   6   7   8   9   10
{1, 3,  2,  1,  4,  1,  3,  2,  1,  1,  2}

(2, 5) --> 2+1+4+1 = 8
(4, 6) --> 4+1+3 = 8
(5, 9) --> 1+3+2+1+1 = 8
*/
#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Approach. TC = O(n3)

Idea is to get all possible subarrays and compare it with the target.
If subarray sum == target, print the start and end index of the subarray.
*/
void subarr_sum_equal_to_target(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int subarr_sum = 0;
            for(int k = i; k <= j; k++)
            {
                subarr_sum += arr[k];
            }

            if(subarr_sum == target)
            {
                printf("%d , %d\n", i, j);
            }
        }
    }
}


/*
Prefix Sum Approach. TC = O(n2), SC = O(n)

Algo:
--> Create new array i.e. prefix_sum.
--> In prefix_sum array, calculate the running sum of all elements previous to index i.
    Ex. arr[] = {1, 3, 2, 5}
        prefix_sum = {1, 1+3, 1+3+2, 1+2+3+5} = {1, 4, 6, 11}
--> The prefix sum is going to sorted array in non decreasing order.
--> For every element at i, find the element at j, such that
    prefix_sum[j] - prefix_sum[i] = target
--> For searching we can use binary search.
*/
/*
int binary_search(int arr[], int size, int key)
{
    int low = 0, mid = 0;
    int high = size - 1;

    // iterate over the array and search for the key
    while(low < high)
    {
        mid = (low + high) / 2; // get mid of two indices.

        // if key is present at the mid, return mid
        if(key == arr[mid])
            return mid;
        // if key is less than value at the mid, make high = mid - 1.
        else if(key < arr[mid])
            high = mid - 1;
        //  if key is greater than the value at the mid, make low = mid + 1.
        else
            low = mid +1;
    }

    return -1;
}


void subarr_sum_equal_to_target_prefixSum(int arr[], int size, int target)
{
    int prefix_sum[11] = {0}; // 11 is nothing but the size of the arr[]

    prefix_sum[0] = arr[0];
    for(int i = 1; i < size; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    for(int i = 0; i < size; i++)
    {
        int j = binary_search(prefix_sum, size, target - prefix_sum[i]);
        if(j != -1)
            printf("%d , %d\n", i, j); // we are printing the indices of prefix_sum array.
    }
}
*/

/*
Sliding Window method. TC = O(n).

Algo: Idea is to calculate sum for particular window enclosed by curr and next pointers.
      If current_sum < target, next++
      If current_sum > target, current_sum - arr[curr], curr++
      If current_sum == target, element found, print(curr, next - 1)

Ex. arr[] = {1, 3, 2, 5, 2}, target = 4

        1,      3,      2,      5,
                        c
                                n
cs 0    1<4   4 == 4    6 > 4   7
              6-1 = 5
              5 > 4     5-3 = 2 < 4
                print(c,n)

*/
void subarr_sum_equal_to_target_optimised(int arr[], int size, int target)
{
    int curr = 0;
    int next = 0;
    int current_sum = 0;

    while(next < size)
    {
        // expand to right. Add the elements to current_sum.
        current_sum += arr[next];
        next++;

        // remove elements from the left till current_sum > target and curr < next.
        while(current_sum > target and curr < next)
        {
            current_sum = current_sum - arr[curr];
            curr++;
        }

        // check if at any given point current_sum == target
        if(current_sum == target)
        {
            //print that window
            cout << curr << " , "<< next - 1 << endl; // next-1 is printed because next++ is done after adding the element.
        }

    }

    return;
}


int main(void)
{
    int arr[] = {1, 3,  2,  1,  4,  1,  3,  2,  1,  1,  2};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);

    subarr_sum_equal_to_target(arr, size, target);
    // subarr_sum_equal_to_target_prefixSum(arr, size, target);
    subarr_sum_equal_to_target_optimised(arr, size, target);

    return 0;
}

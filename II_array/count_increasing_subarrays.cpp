/****************************************************************************
File name: count_increasing_subarrays.cpp

Author: babajr
*****************************************************************************/


/*
Count increasing subarrays.

Read Integers N, then read N < 200 integers.
Find sub array (consecutive numbers) of k elements that has maximum sum.

Input: arr[] = {1, 2, 3, 4}
Output: 10 --> [1], [2], [3], [4], [1,2], [1,2,3], [2,3], [2,3,4], [3,4], [2,4]
(Count how many subarrays are increasing in the array.)

*/

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

/* Approach 1: Brute Force.
TC = O(n3)
*/
/*
int countIncSubarray(int arr[], int size)
{
    int count = 0;
    bool flag = true;

    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j < size - i + 1; j++)
        {
            for(int k = 1; k < i && flag; ++k)
            {
                if(arr[j + k] <= arr[j + k -1])
                    flag = false;
            }

            count += flag;
        }
    }

    return count;
}
*/

/* Approach 2: Instead of checking everytime from the start.. start checking always from next element
   to already checked element.
   input arr: 1    5   7   8   2   3
   First Iter: i = 0
        count = 1
        j = 1 --> arr[1] = 5 > arr[0] --> count = 2
        j = 2 --> arr[2] = 7 > arr[1] --> count = 3
        j = 3 --> arr[3] = 8 > arr[2] --> count = 4
        j = 4 --> arr[4] = 2 < arr[3] --> come out of inner loop
    Second Iter: i = 1
        count = 5
        j = 2 --> arr[2] = 7 > arr[1] --> count = 6
        j = 3 --> arr[3] = 8 > arr[2] --> count = 7
        j = 4 --> arr[4] = 2 < arr[3] --> come out of inner loop
    Third Iter: i = 2
        count = 8
        j = 3 --> arr[3] = 8 > arr[2] --> count = 9
        j = 4 --> arr[4] = 2 < arr[3] --> come out of inner loop
    Fourth Iter: i = 4
        count = 10
        j = 5 --> arr[5] = 2 > arr[4] --> count = 11

    Fifth Iter: i = 5
        count = 12


   TC = O(n2)
 */
/*
int countIncSubarray(int arr[], int size)
{
    int count = 0;

    // Get the start of the array.
    for(int i = 0; i < size; ++i)
    {
        count++; // as given, subarray of size 1 is considered as increasing.

        // Expand subarray as long as it is increasing, else stop expanding.
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] > arr[j - 1]) // increament count if current value is greater than the previous.
                count++;
            else
                break;
        }
    }

    return count;
}
*/

/* Approach 3: Optimal Solution.
   input arr: 1    5   7   8   2   3

   Idea: As from approach 2, we can avoid iterating again and again the increasing subarray elements.
   We will start iterating from next element after increasing subarray ends.

   TC = O(n)
 */
int countIncSubarray(int arr[], int size)
{
    // If we have increasing sequnece of length (n) 4, then we will have (n * (n + 1) / 2) 10 valid
    // increasing subarrays.
    // So find each maximal sub sequence and add them using (n * (n + 1) / 2)
    // OR just increament with length each time we extend it and at the end add size to the count.
    int count = 0;
    int len = 1;

    for(int i = 1; i < size; ++i)
    {
        if(arr[i - 1] <= arr[i])
        {
            count += len;
            ++len;
        }
        else
            len = 1;
    }

    return (count + size);
}


int main()
{
    const int size = 6;
    int count;
    int arr[size] = {1, 5, 7, 8, 2, 3};

    cout<<"Original Array: \n";
    printArray(arr, size);

    count = countIncSubarray(arr, size);

    cout<<"Count of increasing subarrays: "<<count;

    return 0;
}

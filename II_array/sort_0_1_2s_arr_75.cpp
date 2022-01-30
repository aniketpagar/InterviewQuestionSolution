/****************************************************************************
File name: sort_0_1_2s_arr_75.cpp

Author: babajr
*****************************************************************************/


/*
Sort 0's, 1's and 2's in an input array.
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


void printArray(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

/*Approach 1: Just sort.
TC: O(nlogn) --> assuming Merge / Quick sort is used for sorting.
SC: O(1) */
/*
void sort_array(int arr[], int size)
{
    sort(arr, arr + size);
}
*/
/* Approach 2: Using Count sort.
TC: O(n), SC: O(n) */
/*
void sort_array(int arr[], int size)
{
    int num0 = 0, num1 = 0, num2 = 0;

    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == 0)
            num0++;
        else if(arr[i] == 1)
            num1++;
        else
            num2++;
    }

    for(int i = 0; i < num0; ++i)
        arr[i] = 0;
    for(int j = 0; j < num1; ++j)
        arr[num0 + j] = 1;
    for(int k = 0; k < num2; ++k)
        arr[num0 + num1+ k] = 2;
}
*/

/*Approach 3: Dutch National Flag Algorithm.
Three pointer technique.
low -> Elements between [0, low-1] == 0
mid -> Elements between [low, mid] == 1
high -> Elements between [high + 1, end] == 2

Algo:

low = 0, mid = 0, high = end

1. mid == 0:
    swap(a[low], a[mid])
    low++
    mid++
2. mid == 1:
    mid++

3. mid == 2:
    swap(a[mid], a[high])
    high--
*/
void sort_array(int arr[], int size)
{
    int low = 0, mid = 0;
    int high = size - 1;

    while(mid <= high)
    {
        if(arr[mid] == 0) // element is 0
        {
            swap(arr[low], arr[mid]); //swap(arr[low++], arr[mid++]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) // element is 1
        {
            mid++;
        }
        else if(arr[mid] == 2) // element is 2
        {
            swap(arr[high], arr[mid]); //swap(arr[high--], arr[mid]);
            high--;
        }
    }
}

int main()
{
    const int size = 5;
    int min, max, sum;
    // int arr[size] = {1, 2, 3, 4, 5};
    int arr[size] = {1, 2, 1, 0, 0};

    cout<<"Original Array: \n";
    printArray(arr, size);

    sort_array(arr, size);
    cout<<"Sorted Array: \n";
    printArray(arr, size);

    return 0;
}

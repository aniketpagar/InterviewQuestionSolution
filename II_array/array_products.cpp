/****************************************************************************
File name: array_products.cpp

Author: babajr
*****************************************************************************/


/*
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the array with product of all elements except itself.
Approach 1: Using Division.

Idea is to get the product of all the elements and store it in the variable.
Ex. arr[] = {1 2 3 4 5}, product = 120
Now traverse the array, for each element, the result will be product / arr[i].

arr[] = {1 2 3 4 5}
res[] = {120/1, 120/2, 120/3, 120/4, 120/5}

*/
vector<int> productExceptSelf(vector<int> &arr)
{
    int product = 1;
    int size = arr.size();
    vector<int> res(size, 1);

    for(int i = 0; i < size; i++)
        product *= arr[i];

    // traverse the array.
    for(int i = 0; i < size; i++)
    {
        res[i] = product / arr[i];
    }

    return res;
}


/*
API to get the array with product of all elements except itself without using division.

arr[] = {1 2 3 4 5}

Idea is to have two arrays left[] and right[] with size equal to size of input array.

left[] will contain product values

left[0] = 1
left[i] = left[i-1] * arr[i]

right[size-1] = 1
right[i] = right[i+1] * arr[i]

res[i] = left[i] * right[i]
*/
vector<int> productExceptSelf1(vector<int> &arr)
{
    int size = arr.size();
    int i;
    vector<int> res(size, 1), left(size, 1), right(size, 1);

    // get the product of left elements of index.
    left[0] = 1;
    for(i = 1; i < size; i++)
    {
        left[i] = arr[i-1] * left[i-1];
    }

    // get the product of right elements of index.
    right[0] = 1;
    for(i = size - 2; i >= 0; i--)
    {
        right[i] = arr[i+1] * right[i+1];
    }

    // get the final array
    for(i = 0; i < size; i++)
        res[i] = left[i] * right[i];

    return res;
}

void printArr(vector<int> arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}


int main(void)
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> res(arr.size(), 1);

    printArr(arr, arr.size());

    res = productExceptSelf1(arr);
    printArr(res, res.size());

    return 0;
}

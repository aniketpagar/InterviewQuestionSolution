/*
Find the length of longest band. Longest band is a subsequence of array
which can be reordered in a manner all elements appear consecutive.

Input: arr[] = {1,9,3,0,18,5,2,4,10,7,12,6}
Output: 8 (0,1,2,3,4,5,6,7)
*/


#include<bits/stdc++.h>
using namespace std;


/*
Approach 1: Using Sorting.
*/
int longest_band(int arr[], int size)
{
    // sort the array
    sort(arr, arr + size);
    int longest = 1;

    // Check for consecutive subsequnce
    for(int i = 0; i < size - 1; i++)
    {
        int count = 1;

        while(arr[i+1] - arr[i] == 1)
        {
            count++;
            i++;
        }

        longest = max(longest, count);
    }

    return longest;
}


/*
Approach 2: Using unordered_set data structure.
*/
int longest_band_hashing(int arr[], int size)
{
    unordered_set<int> st;

    // push all the elements from the array to set
    for(int i = 0; i < size; i++)
        st.insert(arr[i]);

    int longest = 1; // atleast one element should be present in the array.

    for(int j = 0; j < size; j++)
    {
        int parent = arr[j] - 1;

        // If arr[j] - 1 is not present in the set, find
        // entire band starting from arr[j] - 1.
        // If elements is already present in the set, just ignore.
        if(st.find(parent) == st.end())
        {
            int next_no = arr[j] + 1;
            int count = 1;

            while(st.find(next_no) != st.end())
            {
                next_no++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}


int main(void)
{
    // int arr[] = {1,9,3,0,18,5,2,4,10,7,12,6}; // 8
    int arr[] = {1,3,0,5,2,4,10,7,12,11,13,15,14,16,17}; // 6
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of longest band: " << longest_band(arr, size) << endl;

    cout << "Length of longest band: " << longest_band_hashing(arr, size) << endl;
    return 0;
}

/****************************************************************************
File name: highest_mountain.cpp

Author: babajr
*****************************************************************************/


/*
Return the length of highest mountain. Input given is array of distinct integers.
Mountain --> adjacent integers are strictly increasing until they become peak and then
become strictly decreasing.

PEAK: (1, 2, 1),    (1, 2, 3, 1, 0)
Idea==> First and last element in an array can not be peaks.

Input: arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4}
Output: 9
*/


#include<bits/stdc++.h>
using namespace std;


/*
Approach 1:
Idea is to get all the peaks, and calculate the range of every mountain.
return the mountian with highest length.

        5,  6,  1,  2,  3,  4,  5,  4,  3,  2,  0,  1,  2,  3,  -2,     4

Peaks:      6                   5                   1       3
Len:       (3)                 (9)                 (4)     (5)
*/
int highestMountain(int arr[], int size)
{
    int largest = 0;

    // check for all the peaks.
    for(int i = 1; i < size - 1; i++)
    {
        if(arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            int count = 1;
            int j = i;
            // count backwards
            while(j >= 1 && arr[j] > arr[j-1])
            {
                j--;
                count++;
            }

            // count forward
            while(i <= size - 2 && arr[i] > arr[i+1])
            {
                i++;
                count++;
            }

            largest = max(largest, count);
        }
        else
            i++;
    }

    return largest;
}


int main(void)
{
    int arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4}; // 9
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Height of highest mountain: " << highestMountain(arr, size) << endl;

    return 0;
}

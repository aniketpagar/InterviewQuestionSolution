/****************************************************************************
File name: find_unique_ele_in_arr_of_duplicates_with_single_unique_ele.cpp

Author: babajr
*****************************************************************************/


/*
Program to get the unique element in the
array of all duplicate elements except one unique single element.

Input: arr = [2,1,2,1,4,4,5]
Output: 5
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the unique element in the array of all duplicate elements except one unique single element.

Algo:
--> traverse the array. while traversing xor the elements of array.
    1 xor 1 = 0 i.e. xor of same numbers will be 0.
    1 xor 0 = 1 i.e. xor of two different numbers will be 1.
*/
int get_unique_ele(int arr[], int size)
{
    int unique_single = 0;

    // traverse the array. while traversig do the xor of elements with unique.
    for(int i = 0; i < size; i++)
    {
        unique_single = unique_single ^ arr[i];
    }

    // element remained after xoring all the elements will be the unique element.
    return unique_single;
}


int main(void)
{
    int arr[] = {2,1,2,1,4,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unique element: %d\n", get_unique_ele(arr, size));

    return 0;
}

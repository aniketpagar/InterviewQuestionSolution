/****************************************************************************
File name: remove_even_ele_arr.cpp

Author: babajr
*****************************************************************************/


/*
Implement a function removeEven(int *Arr, int size) which takes an array arr and its
size and removes all the even elements from a given array.

Input: Arr = [1,2,4,5,10,6,3]
Output: Arr = [1,5,3]
*/


#include<bits/stdc++.h>
using namespace std;


/*
API to remove even value elements from the given array.
API returns new size after removal of the even elements.
*/
int removeEven(int *arr, int size)
{
    int k = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 != 0)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    return k;
}


void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}


int main(void)
{
    int arr[] = {1,2,4,5,10,6,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);

    int new_size = removeEven(arr, size);
    print_array(arr, new_size);

    return 0;
}

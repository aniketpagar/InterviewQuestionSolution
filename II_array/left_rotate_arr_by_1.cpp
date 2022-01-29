/****************************************************************************
File name: left_rotate_arr_by_1.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;


/*
API to left rotate the array by 1.
INPUT: arr = [1,2,3,4,5]
OUTPUT: arr = [2,3,4,5,1]

*/
void rotate_left_by_1(int arr[], int size)
{
    int temp = arr[0];
    int i;

    for(i = 1; i < size; i++)
        arr[i - 1] = arr[i];

    arr[i - 1] = temp;
}



void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}


int main(void)
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    print(arr, size);
    rotate_left_by_1(arr, size);
    print(arr, size);

    return 0;
}

/****************************************************************************
File name: insert_element_array.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;


int insert_in_array(int arr[], int size, int val, int pos)
{
    if(pos > size) // pos is out of index. we can not insert element at that position.
        return size;

    // increase the size of array by 1.
    size = size + 1;

    // for(int i = size - 1; i > pos; i--) // 0 based position
    for(int i = size - 1; i >= pos; i--) // 1 based position
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val; // as position is 1 based.
    // arr[pos] = val; // for position 0 based.

    return size; // return new size
}


/*
API to insert element in an array.
*/
int insert_in_array_1(int arr[], int size, int capacity, int val, int pos)
{
    // array is already full, so element can not be inserted.
    if(size == capacity || pos > size)
        return size;

    int index = pos - 1;

    // shift the elements to right side of the pos.
    for(int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    // insert the element at the index.
    arr[index] = val;
    return (size + 1);
}


int main(void)
{
    int arr[] = {1,4,3,2,6};
    int capacity = 10; // maximum size of array
    int val = 5, pos = 1; // pos is 1 based
    int size = sizeof(arr) / sizeof(arr[0]);

    // int new_size = insert_in_array(arr, size, val, pos);
    int new_size = insert_in_array_1(arr, size, capacity, val, pos);

    for(int i = 0; i < new_size; i++)
        printf("%d ", arr[i]);

    return 0;
}

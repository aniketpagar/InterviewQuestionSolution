/*
Program to search the element in an array using recursion.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
API to search element in an array in iterative way.
*/
int search_element_iterative(int arr[], int size, int ele)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == ele)
            return i;
    }

    // if element not found return -1.
    return -1;
}


// /*
// API to search element in an array in recursive way.
// */
// int search_element_recursive(int arr[], int size, int ele)
// {
//     int res;
//     size--;

//     if(size >= 0)
//     {
//         if(arr[size] == ele)
//             return size;
//         else
//             res = search_element_recursive(arr, size, ele);
//     }
//     else // element is not present in the array
//         return -1;
// }


/*
API to search element in an array in recursive way.
*/
int search_element_recursive(int arr[], int size, int ele)
{
    // base case
    if(size < 0)
        return -1;

    if(arr[size] == ele)
        return size;
    else
        return search_element_recursive(arr, size - 1, ele);
}


/*
API to search element in an array in recursive way.
If element is present in the array, return 1 (true) else return 0 (false).
*/
bool search_element_recursive_bool(int arr[], int size, int ele, int index)
{
    // base case
    if(index == size)
        return false;

    return (arr[index] == ele) || (search_element_recursive_bool(arr, size, ele, index + 1));
}


/*
API to return index of element if found in the array. otherwise return -1.
*/
int find_index(int arr[], int size, int ele, int index)
{
    // base case
    if(index == size)
        return -1;

    if(arr[index] == ele)
        return index;
    else
        return find_index(arr, size, ele, index + 1);
}


int main(void)
{
    int arr[] = {1,2,3,4,5};
    int ele = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", search_element_recursive(arr, size - 1, ele));
    printf("%d\n", search_element_recursive_bool(arr, size, ele, 0));
    printf("%d\n", find_index(arr, size, ele, 0));

    return 0;
}

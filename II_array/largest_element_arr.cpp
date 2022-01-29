#include<bits/stdc++.h>
using namespace std;


/*
Brute Force: TC = O(n2)
API to get the largest element in the array.
*/
int largest_ele_arr_bf(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        bool flag = true; // current element is largest
        for(int j = 0; j < size; j++)
        {
            if(arr[j] > arr[i]) // greater element than current element found.
            {
                flag = false;
                break;
            }
        }

        if(flag == true)
            return i; // returning the index of the largest element.
    }

    return -1; // this line will never be executed, we are writing just to match the return type of the API.
}


/*
Efficient Solution: TC = O(n)
API to get the largest element in the array.
*/
int largest_ele_arr_eff(int arr[], int size)
{
    int largest = arr[0];
    int index = 0;

    // traverse the array and update the largest element.
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
            index = i;
        }
    }

    return index;
}


int main(void)
{
    int arr[] = {10, 5, 10, 100, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Index of largest element: %d\n", largest_ele_arr_bf(arr, size));
    printf("Index of largest element: %d\n", largest_ele_arr_eff(arr, size));

    return 0;
}

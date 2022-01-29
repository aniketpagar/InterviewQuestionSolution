#include<bits/stdc++.h>
using namespace std;



void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}

/*
API to rotate array clockwise by k elements.
INPUT: arr = [1,2,3,4,5] , k = 2
OUTPUT: arr = [3,4,5,1,2]

Brute Force.
--> Take temp array to store the k elements to be rotated.
--> shift the other elements to the left by k.
--> append the elements from temp to array.
*/
void rotate_left(int arr[], int size, int k)
{
    int *temp = (int *)malloc(sizeof(int) * k);
    int i;

    // copy first k elements to the temp array
    for(i = 0; i < k; i++)
        temp[i] = arr[i];

    // left shift the remaining elements by k
    for(i = k; i < size; i++)
        arr[i - k] = arr[i];

    // append the elements from temp array to array
    for(int j = 0; j < k; j++)
        arr[j + size - k] = temp[j];
}


void rotate_left_by_1(int arr[], int size)
{
    int temp = arr[0];
    int i;

    for(i = 1; i < size; i++)
        arr[i - 1] = arr[i];

    arr[i - 1] = temp;
}

/*
Efficient Approach.

The idea is to rotate the array one by one K times.
To rotate an array by 1 position to the left:
--> Store the first element in a temporary variable say temp.
--> Left shift all elements after the first element by 1 position.
    That is, move arr[1] to arr[0], arr[2] to arr[1] and so on.
--> Initialize arr[N-1] with temp.
*/
void rotate_left_eff(int arr[], int size, int k)
{
    for(int i = 0; i < k; i++)
    {
        rotate_left_by_1(arr, size);
        print(arr, size);
    }
}


int main(void)
{
    int arr[] = {1,2,3,4,5};
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    // print(arr, size);
    // rotate_left(arr, size, k);
    // print(arr, size);

    rotate_left_eff(arr, size, k);
    print(arr, size);

    return 0;
}

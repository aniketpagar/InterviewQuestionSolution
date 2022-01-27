/*
Replace all min elements in an array with max elements.
Input: [1, 1, 3, 4, 5]
Output: [5, 5, 3, 4, 1]
*/
#include <iostream>
#include <cassert>
using namespace std;

#define TRUE    1
#define FALSE   0

int getMax(int arr[], int size)
{
    int max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

int getMin(int arr[], int size)
{
    int min = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}

void replaceMinMax(int arr[], int size)
{
    int min = getMin(arr, size);
    int max = getMax(arr, size);

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == min)
            arr[i] = max;
        else if(arr[i] == max)
            arr[i] = min;
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    const int size = 5;
    int arr[size] = {1, 1, 3, 5, 5};

    cout<<"Original Array: \n";
    printArray(arr, size);

    cout<<"Modified Array: \n";
    replaceMinMax(arr, size);
    printArray(arr, size);

    return 0;
}

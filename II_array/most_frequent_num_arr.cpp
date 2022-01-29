/****************************************************************************
File name: most_frequent_num_arr.cpp

Author: babajr
*****************************************************************************/


#include <iostream>
#include <cassert>
using namespace std;

/* Approach 1: TC = O(n2) */
/*
int getMostFreqNum(int arr[], int size)
{
    int max_repeat = -1;
    int max_val = -1;

    for(int i = 0; i < size; ++i)
    {
        int repeat = 0;
        for(int j = 0; j < size; ++j)
        {
            if(arr[i] == arr[j])
                repeat += 1;
        }
        if(max_repeat == -1 || max_repeat < repeat)
        {
            max_repeat = repeat;
            max_val = arr[i];
        }
    }

    if(max_repeat == 1)
        return -1;

    cout<<max_val<<" repeated "<<max_repeat<<" times \n";
    return max_val;
}
*/

/*Approach 2: using another array. TC = O(n). */
int getMostFreqNum(int arr[], int size)
{
    int freq[150 + 1] = {0}; //range of numbers 0 to 150 is given in the question
    int max_pos = -1;

    for(int i = 0; i < size; ++i)
        freq[arr[i]]++;

    for(int j = 0; j < 151; j++)
    {
        if(max_pos == -1 || (freq[max_pos] < freq[j]))
            max_pos = j;
    }

    return max_pos;
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
    int most_freq_num;
    int arr[size] = {1, 1, 3, 1, 5};

    cout<<"Original Array: \n";
    printArray(arr, size);

    most_freq_num = getMostFreqNum(arr, size);

    if(most_freq_num == -1)
        cout<<"No repeating number in an array\n";
    else
        cout<<"Most frequent number in an array is: \t"<<most_freq_num;

    return 0;
}

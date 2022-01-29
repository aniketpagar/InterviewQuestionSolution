/****************************************************************************
File name: count_set_bits_num.cpp

Author: babajr
*****************************************************************************/


/*
Count the number of ones in the binary representation of the given number.
Input: 4 (0100)
Output: 1
*/

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


/*Approach 1: using Brian Kernighan’s. */
/*
int countSetBits(int num)
{
    int count = 0;
    while(num > 0)
    {
        num = num & (num - 1);
        count++;
    }

    return count;
}
*/

/*Approach 2*/

int countSetBits(int num)
{
    int count = 0;
    while(num > 0)
    {
        count += num & 1;
        num = num >> 1;
    }

    return count;
}


int main(void)
{
    int num, SetBitsCount;

    cout<<"Please Enter the number: ";
    cin>>num;

    SetBitsCount = countSetBits(num);
    cout<<"Set Bits in "<<num<<" are "<<SetBitsCount;

    return 0;
}

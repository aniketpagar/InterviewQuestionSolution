/****************************************************************************
File name: check_ith_bit_set.cpp

Author: babajr
*****************************************************************************/


/*
Check if the ith bit is set in the binary form of the given number.
Input: N = 4 (0100), i = 0
Output: 0 -->
*/

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


/*Approach 1 */

int checkSetBit(int num, int i)
{
    // (1 << i) --> 2 ^ i.
    // We are shifting 1 by i and checking whether ith bit in num is set or not.
    if(num & (1 << i))
        return 1;
    else
        return -1;
}


int main(void)
{
    int num, checkBit, i;

    cout<<"Please Enter the number: ";
    cin>>num;
    cout<<"Please Enter the bit to check: ";
    cin>>i;

    checkBit = checkSetBit(num, i);

    if(checkBit == 1)
        cout<<i<<"th bit is set";
    else
        cout<<i<<"th bit is not set";

    return 0;
}

/****************************************************************************
File name: find_position_of_rightmost_set_bit.cpp

Author: babajr
*****************************************************************************/


/*
Program to return position of first 1 from right to left, in binary representation
of an Integer.

I/P:    18,   Binary Representation 010010
O/P:   2
I/P:    19,   Binary Representation 010011
O/P:   1
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to return the position of the right most set bit.
*/
int position_of_rightmost_set_bit(int num)
{
    int position = 1; // assuming position starts with 1 rather than 0.
    int index = 1; // variable used to check the set bit.

    if(num == 0)
        return 0;

    while(!(num & index)) // continue traversing the loop until first set bit is found.
    {
        // shift the index to left by 1.
        index = index << 1;
        position++;
    }

    return position;
}


/*Another way*/
int position_of_rightmost_set_bit_1(int num)
{
    if(num == 0)
        return 0;

    int position = 1;
    for(int i = 0; i < 32; i++)
    {
        if(!(num & (1 << i)))
            position++;
        else break;
    }

    return position;
}


int main(void)
{
    int num = 10;

    printf("Position of the rightmost set bit: %d\n", position_of_rightmost_set_bit(num));
    printf("Position of the rightmost set bit: %d\n", position_of_rightmost_set_bit_1(num));

    return 0;
}

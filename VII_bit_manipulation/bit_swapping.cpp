/****************************************************************************
File name: bit_swapping.cpp

Author: babajr
*****************************************************************************/


#include<stdio.h>

int swap_bits(int n)
{
    int res = 0;
    res = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    return res;
}

int swap_two_bits(int n)
{
    int res = 0;
    res = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    return res;
}

int swap_nibble(int n)
{
    int res = 0;
    res = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    return res;
}

int swap_octet(int n)
{
    int res = 0;
    res = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    return res;
}


int main(void)
{
    int num = 10;
    int res;

    res = swap_bits(num);
    printf("Result after bits swapped: %d\n", res);

    res = swap_two_bits(num);
    printf("Result after two bits swapped: %d\n", res);

    res = swap_nibble(num);
    printf("Result after nibble swapped: %d\n", res);

    res = swap_octet(num);
    printf("Result after octets swapped: %d\n", res);

    return 0;
}

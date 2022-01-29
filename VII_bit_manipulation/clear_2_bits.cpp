/****************************************************************************
File name: clear_2_bits.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;


/*
API to clear 2 bits of a given 32 bit number.
*/
void clear_2_bits(int num, int bit1, int bit2)
{
    // Brute Force
    /*
    int res = num & ~(1 << bit1);
    printf("%d\n", res);

    res = res & ~(1 << bit2);

    printf("%d\n", res);
    */

    // Better
    int res = num & ~((1 << bit1) | (1 << bit2));
    printf("%d\n", res);
}


int main(void)
{
    int num = 15; // 1111

    int bit1 = 1, bit2 = 0;

    clear_2_bits(num, bit1, bit2);

    return 0;
}

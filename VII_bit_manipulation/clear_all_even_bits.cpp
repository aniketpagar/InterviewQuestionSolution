/****************************************************************************
File name: clear_all_even_bits.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;


/*
API to clear all even bits of a given 32 bit number having all set bits.
*/
int clear_even_bits(int num)
{
    int res = (num & 0xaaaaaaaa);
    return res;
}


int main(void)
{
    int num = 65535;

    printf("%d\n", clear_even_bits(num));

    return 0;
}

/****************************************************************************
File name: base_b_to_decimal_conversion.cpp

Author: babajr
*****************************************************************************/


/*
Convert the num with base b to decimal number.

(10001) base 2 = 17 base 10
(21) base 8 = 17 base 10.

Algo:
--> multiply the power of base with digits of binary number.
--> add them


10001 base 2 ==> decimal

    1 * (2^4) + 0 * (2^3) + 0 * (2^2) + 0 * (2^1) + 1 * (2^0)
==> 16  +   0   +   0   +   0   + 1
==> 17

*/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


void binary_to_decimal(int bin_num)
{
    int dec_num = 0;
    int base = 1;

    while(bin_num > 0)
    {
        int last_digit = bin_num % 10;
        bin_num = bin_num / 10;

        dec_num += last_digit * base;
        base = base * 2;
    }

    printf("Decimal No: %d\n", dec_num);
}


int main(void)
{
    int bin_num = 10001; // binary - 10001

    binary_to_decimal(bin_num);

    return 0;
}

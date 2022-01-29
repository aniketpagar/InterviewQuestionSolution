/****************************************************************************
File name: decimal_to_base_b_conversion.cpp

Author: babajr
*****************************************************************************/


/*
Decimal to Base b conversion: (num) base (10) = (num2) base b.

Ex:
    (17) base 10 = (10001) base 2
    (17) base 10 = (21) base 8

Algo:
--> keep deviding the decimal number with base b until it becomes 0,
    and take remainders and write/print it in opposite.

    17 % 2 = 1, 17/2 = 8
    8 % 2 = 0,  8/2 = 4
    4 % 2 = 0,  4/2 = 2
    2 % 2 = 0,  2/2 = 1
    1 % 2 = 1,  1/2 = 0

Ouput = (10001) base 2

    17 % 8 = 1, 17/8 = 2
    2 % 8 = 2, 2/8 = 0

Output = (21) base 8.
*/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


/*
API to convert decimal to binary number.
*/
void decimal_to_base_b(int num, int base)
{
    int base_arr[32] = {0};
    int i = 0;

    while(num > 0)
    {
        // get the remainder
        base_arr[i] = num % base;
        num = num / base;
        i++;
    }

    // print the value in base_arr in reverse form.
    for(i = 31; i >= 0; i--)
        printf("%d ", base_arr[i]);
}


int main(void)
{
    int num = 17; // decimal number
    int base = 8; // 2 - binary, 8 - octal

    decimal_to_base_b(num, base);

    return 0;
}

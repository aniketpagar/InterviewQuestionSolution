/****************************************************************************
File name: odd_even.cpp

Author: babajr
*****************************************************************************/


/*
Program to find the given number is odd or even.
*/

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


/*
API to find the given numis odd or even.

Algo:
--> use bitwise AND operator to check if LSB of num is 1 or 0.
--> if it is ==> 1, then its ODD number
    else, it is EVEN number.
*/
bool odd_even(int num)
{
    if(num & 1 == 1) // 1010 & 1 = 0, 1011 & 1 = 1
        return 1; // ODD number
    else
        return 0; // EVEN number
}


int main(void)
{
    int num = 11;

    if(odd_even(num) == 1)
        printf("ODD Num\n");
    else
        printf("EVEN Num\n");

    return 0;
}

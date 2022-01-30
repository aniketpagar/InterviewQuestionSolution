/****************************************************************************
File name: smallest_num_rearranging_digit_num.cpp

Author: babajr
*****************************************************************************/


/*
Find the Smallest number (Not leading Zeros) which can be obtained by
rearranging the digits of a given number.

Input: n = 846903
Output: 304689

Input: n = 55010
Output: 10055

Input: n = -40505
Output: -55400
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the smallest number after rearranging the digits of the number.

Algo:
--> Count the frequency of the digits using frequency[].
--> Get the left most digit i.e. smallest digit other than 0.
--> Arrange remaining digits in ascending order.
*/
int smallest(int num)
{
    // frequency array to count the frequency of digits.
    int frequency[10] = {0};
    int res = 0;

    while(num > 0)
    {
        int digit = num % 10;
        frequency[digit]++;
        num = num / 10;
    }

    // get the smallest digit as the highest digit of a number
    // starting from 1 as smallest number starting other than 0 is asked.
    for(int i = 1; i <= 9; i++)
    {
        if(frequency[i] > 0)
        {
            res = i;
            frequency[i]--;
            break;
        }
    }

    // arrange the other digits in ascending order in res variable.
    for(int j = 0; j <= 9; j++)
    {
        while(frequency[j]-- > 0)
        {
            res = res * 10 + j;
        }
    }

    return res;
}


/*
API to get largest num after rearranging the digits of the number.
*/
int largest(int num)
{
    // frequency array to count the frequency of digits.
    int frequency[10] = {0};
    int res = 0;

    while(num > 0)
    {
        int digit = num % 10;
        frequency[digit]++;
        num = num / 10;
    }

    // get the largest digit as the highest digit of a number
    for(int i = 9; i >= 0; i--)
    {
        if(frequency[i] > 0)
        {
            res = i;
            frequency[i]--;
            break;
        }
    }

    // arrange the other digits in descending order in res variable.
    for(int j = 9; j >= 0; j--)
    {
        while(frequency[j]-- > 0)
        {
            res = res * 10 + j;
        }
    }

    return res;
}


int main(void)
{
    int num = 846903;

    printf("Smallest Number after rearrangement of digits : %d\n",
        smallest(num));

    printf("Largest Number after rearrangement of digits : %d\n",
        largest(num));

    return 0;
}

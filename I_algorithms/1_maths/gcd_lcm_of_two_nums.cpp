/****************************************************************************
File name: gcd_lcm_of_two_nums.cpp

Author: babajr
*****************************************************************************/


/*
Program to get the GCD and LCM of two numbers

GCD / HCF : Greatest Common Divisor / Highest Common Factor == highest factor dividing a and b.
LCM : Least Common Multiple == minimum number divisible by a and b.
Ex:
a = 18, b = 9 ==>
factors(a) = 2 * 3 * 3
factors(b) = 3 * 3

GCD = 9
LCM = 18


*/

#include <bits/stdc++.h>
using namespace std;


/*
API to get the GCD of two numbers.
*/
int gcd(int a, int b)
{
    if(a == 0)
        return b;

    return gcd(b % a, a);
}


/*
API to get the LCM of two numbers.
*/
int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}


int main(void)
{
    int a = 9, b = 4;

    printf("GCD: %d\n", gcd(a, b));
    printf("lcm: %d\n", lcm(a, b));

    return 0;
}

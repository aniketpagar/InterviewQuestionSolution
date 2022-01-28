/*
Program to count the number of zeros in the given number.

Input: num = 103020
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;


/*
Helper API to get the count of zero digits in a number.
*/
int helper(int num, int count_of_zeros)
{
    if(num == 0)
        return count_of_zeros;

    int rem = num % 10;

    if(rem == 0) // digit is zero. call the function recursively with increase count.
        return helper(num / 10, count_of_zeros + 1);

    // digit is not zero, call tha function recursively
    // with same count.
    return helper(num / 10, count_of_zeros);
}


/*
API to get the number of zeros in a number.
*/
int count_zeros(int num)
{
    return helper(num, 0); // API takes two inputs: num, count_of_zeros
}


int main(void)
{
    int num = 0;

    printf("Count of Zeros: %d\n", count_zeros(num));


    return 0;
}

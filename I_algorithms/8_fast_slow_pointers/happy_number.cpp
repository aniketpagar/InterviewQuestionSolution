/****************************************************************************
File name: happy_number.cpp

Author: babajr
*****************************************************************************/


/*
Any number will be called a happy number if, after repeatedly replacing it with a
number equal to the sum of the square of all of its digits, leads us to number ‘1’.
All other (not-happy) numbers will never reach ‘1’.
Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Input: 23
Output: true (23 is a happy number)
Explanations: Here are the steps to find out that 23 is a happy number

2^2 + 3^2 = 13
1^2 + 3^2 = 10
1^2 + 0^2 = 1

Input: 12
Output: false (12 is not a happy number)
Explanations: Here are the steps to find out that 12 is not a happy number

1^2 + 2^2 = 5
5^2 = 25
2^2 + 5^2 = 29
2^2 + 9^2 = 85
8^2 + 5^2 = 89
.
.
.
*/

#include<bits/stdc++.h>
using namespace std;


/*
Helper function to get the squared sum of digits of the number.
*/
int get_square_sum(int num)
{
    int digit, sum = 0;

    while(num > 0)
    {
        // get the digit of the number.
        digit = num % 10;
        // get the sqaured sum
        sum += digit * digit;
        // update the number in order to get the next digit.
        num = num / 10;
    }

    return sum;
}


/*
API to find whether the given number is happy number or not.

Every number will definitely have a cycle. Therefore, we will use the fast & slow pointer
strategy to find the cycle and once the cycle is found, we will see if the cycle is
stuck on number ‘1’ to find out if the number is happy or not.
*/
bool is_happy_number(int num)
{
    int slow = num;
    int fast = num;

    do
    {
        // move one step.
        slow = get_square_sum(slow);
        // move two steps.
        fast = get_square_sum(get_square_sum(fast));
    } while(slow != fast);

    // check if cycle is ending on 1 or not.
    if(slow == 1)
        return true; // number is happy number.
    else
        return false;
}


int main(void)
{
    int num = 12;

    if(is_happy_number(num))
        printf("Number is a HAPPY NUMBER\n");
    else
        printf("Number is NOT HAPPY NUMBER\n");

    return 0;
}

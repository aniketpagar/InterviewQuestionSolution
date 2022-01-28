/*
Program to reverse the digits of a number.

Input: 1234
Output: 4321

rev(num) => number of digits = digit
    ==> call helper API: helper(num/10, digit)
                            return ((num % 10) * (10 ^ (digit-1)) + helper(num/10, digit-1))

*/

#include <bits/stdc++.h>
using namespace std;


/*
Simple Approach. It works but this is not the right way to do it.
*/
// int reverse(int num)
// {
//     int rem;
//     static int sum;

//     // base case
//     if(num == 0)
//         return sum;

//     rem = num % 10;
//     sum = sum * 10 + rem;

//     // recursive call
//     reverse(num / 10); // it should return but we are not returning any thing.
//                        // so not the correct approach.
// }


/*
Helper API to reverse the digits of the number.
*/
int helper(int num, int digit)
{
    if(num % 10 == num) // base case. when only single digit is remaining.
        return num;

    int rem = num % 10;

    return ((rem * pow(10, digit-1)) + (helper(num / 10, digit - 1)));
}


/*
API to reverse the number.
*/
int reverse_digits(int num)
{
    // we will use another function to do the task for us.
    // get the number of digits.
    int digit = 0;
    int temp = num;
    while(temp > 0)
    {
        digit++;
        temp = temp / 10;
    }

    // another way to calculate digits
    // digit = (int) log10(num) + 1;

    // use helper function to get the reverse of the number.
    return helper(num, digit);
}


int main()
{
    int num = 5646;

    printf("Original Number : %d\n", num);
    printf("Reversed Number: %d\n", reverse_digits(num));

    return 0;
}

/*
Program to check if a given number is palindrome or not.

Input: 1221
Output: Yes
*/

#include <bits/stdc++.h>
using namespace std;


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


/*
API to check whether the given number is palindrome or not.
*/
bool is_palindrome(int num)
{
    return num == reverse_digits(num);
}


int main()
{
    int num = 121;

    printf("Original Number : %d\n", num);
    printf("Reversed Number: %d\n", reverse_digits(num));

    if(is_palindrome(num) == true)
        printf("palindrome\n");
    else
        printf("not palindrome\n");

    return 0;
}

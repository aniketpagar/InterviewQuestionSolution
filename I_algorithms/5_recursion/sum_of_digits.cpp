/*
Program to get the sum of all the digits in the number.

Input: num = 123
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to get the sum of all digits in a number.
*/
int sum_of_digits(int num)
{
    if(num == 0)
        return 0;

    return (num % 10) + sum_of_digits(num / 10);
}


/*
API to get the product of all digits in a number
*/
int product(int num)
{
    if(num % 10 == num)
        return num;

    return (num % 10) * product(num / 10);
}


int main(void)
{
    int num = 55;

    printf("Sum of digits: %d\n", sum_of_digits(num));
    printf("Product of digits: %d\n", product(num));

    return 0;
}

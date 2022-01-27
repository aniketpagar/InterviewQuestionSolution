/*
Check if given number is prime or not. Number less than 1 is assumed as non prime number.

Input: 2
Output: Yes

Input: 5
Output: Yes

Input: 8
Output: No
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to check if given number is prime or not.
Prime Number: number divisible by 1 and itself is prime number.

Idea is to check if num is divisible by (2 to sqrt(num)).
If divisible, Not Prime. Else, number is prime.
*/
bool is_prime(int num)
{
    if(num <= 1)
        return false;

    int factor = 2;

    while(factor * factor <= num) // if(factor <= sqrt(num))
    {
        if(num % factor == 0) // num is not prime.
            return false;

        factor++;
    }

    return true;
}


int main(void)
{
    int num = 2;

    if(is_prime(num) == true)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

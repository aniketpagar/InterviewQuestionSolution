/*
Print prime numbers less than number.

Input: n = 10
Output: 2 3 5 7

Input: 15
Output: 2 3 5 7 11 13

*/

#include <bits/stdc++.h>
using namespace std;


/*
Helper API to check if given number is prime or not.
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


/*
Brute Force:
API to print the prime numbers whose value is less than given num.
TC: O(n * sqrt(n))
*/
void print_prime_numbers(int num)
{
    for(int i = 2; i <= num; i++) // i = 2, 1 is not prime number.
    {
        printf("%d : %d,\t", i, is_prime(i));
    }
}


/*
Optimised Solution: Sieve of eratosthenes.
SC: O(n)
TC: O(n * log(log n))

Idea is to use arr[] of size num + 1 and intialise it with 0/false.
False in arr[] ==> number is prime.
True in arr[] ==> number is not prime.
Traverse the array from 2, and check each element for prime.
If number is prime, then mark multiple of it in arr[] as true i.e. not prime.
*/
void sieve_of_eratosthenes(int num)
{
    // array of size num + 1 to mark the particaular element as true / false.
    bool *prime = (bool *)calloc(1, (num + 1));
    // bool prime[num + 1] = {0};

    // false ==> prime, true ==> not prime.
    for(int i = 2; i * i <= num; i++)
    {
        if(prime[i] == false) // num is prime
        {
            // mark multiple of num/i as true i.e. not prime.
            for(int j = (i * 2); j <= num; j += i)
                prime[j] = true;
        }
    }

    // print the elements in the prime[].
    for(int k = 2; k <= num; k++)
    {
        if(prime[k] == false)
            printf("%d,  ", k);
    }
}


int main(void)
{
    int num = 20;

    print_prime_numbers(num);
    printf("\n");

    sieve_of_eratosthenes(num);

    return 0;
}

/****************************************************************************
File name: factors_of_num.cpp

Author: babajr
*****************************************************************************/


/*
Print the factors of the the given number.

Input: 20
Output: 1, 2, 4, 5, 10, 20
*/

#include <bits/stdc++.h>
using namespace std;


/*
Brute Force: TC : O(n)
API to print all the factors of the number.
*/
void print_factors(int num)
{
    for(int i = 1; i <= num; i++)
        if(num % i == 0)
            printf("%d, ", i);
}


/*
Efficient Approach. TC : O(sqrt(n))

Input: 20
Output: 1, 20, 2, 10, 4, 5 (Output is not in sorted order)
*/
void print_factors_efficient(int num)
{
    for(int i = 1; i < sqrt(num); i++)
    {
        if(num % i == 0) // i is factor of a number
        {
            if(num / i == i) // 36 ==> 36/6 = 6 ==> to avoid printing 6 two times.
                printf("%d, ", i);
            else
                printf("%d, %d, ", i, num/i);
        }
    }
}


int main(void)
{
    int num = 20;

    print_factors(num);
    printf("\n");
    print_factors_efficient(num);

    return 0;
}

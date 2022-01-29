/*
Program to get the factorial of a given number.

Input: num = 5
Output: 120
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to get the factorial of given input number.
*/
int fact(int num)
{
    if(num <= 1)
        return 1;

    return num * fact(num - 1);
}


int main(void)
{
    int num = 5;

    printf("Factorial is: %d\n", fact(num));

    return 0;
}

/****************************************************************************
File name: sqrt_of_num.cpp

Author: babajr
*****************************************************************************/


/*
Program to find the square root of a number.

Input: 36
Output: 6

Input: 40
Output: 6.32 // assuming only 2 decimal points
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to get the square root of a number using the binary search.

TC : O(log n)

Algo:

--> mid = (start + end) / 2;

--> if(mid * mid > num)
        end = mid - 1
--> else if(mid * mid < num)
        start = mid + 1;
--> else
        return mid.

Input: num = 16

        1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16
        s                           m                                e
                                64  > 16
        s           m           e
                16  =  16 ==> ANS = 4
*/
double sqrt_of_num(int num, int precision)
{
    int start = 0;
    int end = num;
    double root = 0.0;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(mid * mid == num)
            return mid;
        else if(mid * mid > num)
            end = mid - 1;
        else
        {
            start = mid + 1;
            root = mid; // if num is not perfect sqaure
        }
    }

    // if num is not perfect square, get the decimal values upto mentioned
    // precision with following logic.
    double incr = 0.1;
    for(int i = 0; i < precision; i++)
    {
        while(root * root <= num)
            root += incr;

        root -= incr;
        incr /= 10;
    }

    return root;
}



int main(void)
{
    int num = 40;
    int precision = 2;

    printf("Sqrt(%d) = %f", num, sqrt_of_num(num, precision));

    return 0;
}

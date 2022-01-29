/****************************************************************************
File name: find_largest_power_of_2.cpp

Author: babajr
*****************************************************************************/


/*
Find the largest power of 2 (most significant bit in binary form),
which is less than or equal to the given number N.
Idea: Change all the bits which are at the right side of the most significant digit, to 1.
Input: 21
Output: 16
*/

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


/*Approach 1*/
/* Logic:
Let’s say N = 21 = {10101}, here most significant bit is the 4th one.
(counting from 0th digit) and so the answer should be 16.
So lets change all the right side bits of the most significant bit to 1.
Now the number changes to
{11111} = 31 = 2 * 16 -1 = Y (let’s say).
Now the required answer is (Y+1)>>1 or (Y+1)/2.
*/
long largest_power(long num)
{
    // Change all right side bits of MSB set bit to 1.
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);

    // //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by 2.
    return (num + 1) >> 1; // (num + 1) / 2
}


/*
Approach 2: TC = O(n)

Idea: start checking from num and keep decrementing until we find power of 2.
*/
int largest_power_1(int num)
{
    int res = 0;

    for(int i = num; i >= 1; i--)
    {
        // check if num is power of 2.
        if((i & (i - 1)) == 0)
        {
            res = i;
            break;
        }
    }

    return res;
}


/*
Approach 3: TC = O(n)

Idea: Use bitwise left shift operator.
*/
int largest_power_2(int num)
{
    if(num <= 0)
        return 0;

    int res = 1;
    // assuming num is of 32 bits.
    for(int i = 0; i < 32; i++)
    {
        int power_curr = 1 << i; // get the power of 2 for all the possible positions.
        // if power_curr is more than input num, no need to check further.
        if(power_curr > num)
            break;

        res = power_curr;
    }

    return res;
}


int main(void)
{
    long num;

    cout<<"Please Enter the number: ";
    cin>>num;

    printf("%d \n", largest_power(num));
    printf("%d \n", largest_power_1(num));
    printf("%d \n", largest_power_2(num));

    return 0;
}

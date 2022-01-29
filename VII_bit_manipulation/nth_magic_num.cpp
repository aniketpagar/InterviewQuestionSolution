/*
Program to get the nth magic number.

Magic Number:

input       output
1 (0001)        5
2 (0010)        25
3 (0011)        25 + 5 = 30
4 (0100)        125
5 (0101)        130

*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the nth magic number.
*/
int nth_magic_num(int n)
{
    int magic_number = 0;
    int base = 5;

    while(n > 0)
    {
        // get the last bit and right shift n by 1.
        int last_bit = n & 1;
        n = n >> 1;

        magic_number = magic_number + (base * last_bit);
        base = base * 5;
    }

    return magic_number;
}


int main(void)
{
    int n = 3;

    printf("nth Magic Number: %d\n", nth_magic_num(n));

    return 0;
}

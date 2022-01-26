/*
Check if a given number is a power of 2. On success return True(1) else, return False(-1)
Input: 4
Output: True (1)

*/

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/* Approach 1: General way. */
/*
int isPowerOfTwo(int num)
{
    if(num == 0) // special case
        return -1;
    else
    {
        while(num % 2 == 0)
            num /= 2;

        return (num == 1);
    }
}
*/

/*Approach 2: Using bitwise operator. */
int isPowerOfTwo(int num)
{
    return (num && !(num & (num - 1))); // num will check if num == 0 and !(num & (num - 1)) will check if it's power of 2.
}


int main(void)
{
    int num;

    cout<<"Please Enter the number: ";
    cin>>num;

    if(isPowerOfTwo(num))
        cout<<num<<" is power of 2\n";
    else
        cout<<num<<" is not power of 2\n";


    return 0;
}

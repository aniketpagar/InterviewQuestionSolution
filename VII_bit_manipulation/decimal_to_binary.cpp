/****************************************************************************
File name: decimal_to_binary.cpp

Author: babajr
*****************************************************************************/


#include<bits/stdc++.h>
using namespace std;


/*
API to convert decimal number to binary number.
*/
void dec_to_binary(int n)
{
    /* array to store binary bits */
    int arr_bin[32];
    int iter = 0;

    while(n > 0)
    {
        arr_bin[iter] = n % 2;
        n = n /2;
        iter++;
    }

    /* print array in reverse */
    for(int j = iter - 1; j >= 0; j--)
        cout << arr_bin[j] << " ";

    cout << endl;
}


/*
API to convert decimal number to binary number.
*/
#define CHAR_BITS   8
#define INT_BITS    (sizeof(int) * CHAR_BITS)

void dec_to_binary_bitwise(int num)
{
    for(int pos = (INT_BITS - 1); pos >= 0 ; pos--)
    {
        (num & (1 << pos)) ? printf("1") : printf("0");
    }
}


/* API to convert decimal to octal. */
void dec_to_octal(int n)
{
    /* array to store octal digits */
    int arr_octal[100];
    int iter = 0;

    while(n > 0)
    {
        arr_octal[iter] = n % 8;
        n = n / 8;
        iter++;
    }

    /* print array in reverse */
    for(int j = iter - 1; j >= 0; j--)
        cout << arr_octal[j] << " ";

    cout << endl;
}


/* API to convert decimal to hexadecimal. */
void dec_to_hex(int n)
{
    /* array to store hex digits */
    int arr_hex[100];
    int iter = 0;

    while(n != 0)
    {
        int temp = 0;
        temp = n % 16;

        if(temp < 10)
        {
            arr_hex[iter] = temp + 48;
            iter++;
        }
        else
        {
            arr_hex[iter] = temp + 55;
            iter++;
        }
        n = n / 16;
    }

    /* print array in reverse */
    for(int j = iter - 1; j >= 0; j--)
        cout << to_string(arr_hex[j]) << " ";

    cout << endl;
}


int main(void)
{
    int num;

    cout << "Enter Number: " << endl;
    cin >> num;

    cout << "DECIMAL TO BINARY" << endl;
    dec_to_binary(num);

    cout << "DECIMAL TO OCTAL" << endl;
    dec_to_octal(num);

    // cout << "DECIMAL TO HEX" << endl;
    // dec_to_hex(num);

    return 0;
}

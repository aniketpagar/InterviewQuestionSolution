/*
Letter Combinations of a Phone Number.
*/
#include <bits/stdc++.h>
using namespace std;


void phone_pad(string processed, string un_processed)
{
    if(un_processed.length() == 0)
    {
        cout << processed << endl;
        return;
    }

    int digit = un_processed[0] - '0'; // converting char to number
                                       // i.e. '2' --> 2
    for(int i = (digit - 1) * 3; i < (digit * 3); i++)
    {
        char ch = (char) ('a' + i);
        phone_pad(processed + ch, un_processed.substr(1));
    }
}


int phone_pad_count(string processed, string un_processed)
{
    if(un_processed.length() == 0)
    {
        return 1;
    }

    int digit = un_processed[0] - '0'; // converting char to number
                                       // i.e. '2' --> 2
    int count = 0;
    for(int i = (digit - 1) * 3; i < (digit * 3); i++)
    {
        char ch = (char) ('a' + i);
        count = count + phone_pad_count(processed + ch, un_processed.substr(1));
    }

    return count;
}

int main(void)
{
    phone_pad("", "12"); // phone_pad(string processed, string un_processed)
    printf("%d\n", phone_pad_count("", "12"));

    return 0;
}

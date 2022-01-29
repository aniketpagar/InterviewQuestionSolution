/****************************************************************************
File name: generate_all_subsets_subsequences.cpp

Author: babajr
*****************************************************************************/


/*
Input: array = {1, 2, 3}
Output: // this space denotes null element.
         1
         1 2
         1 2 3
         1 3
         2
         2 3
         3
Explanation: These are all the subsets that can be formed using the array.
*/
#include <bits/stdc++.h>
using namespace std;


void generate_subsets(string output, string original)
{
    // base case
    if(original.length() == 0)
    {
        cout << output << endl;
        return;
    }

    // get the first char
    char ch = original[0];
    // recursive call with ch included.
    generate_subsets(output + ch, original.substr(1));
    // recursive call with ch excluded.
    generate_subsets(output, original.substr(1));
}


int main(void)
{
    string original = "abc";
    string output = "";

    generate_subsets(output, original);

    return 0;
}

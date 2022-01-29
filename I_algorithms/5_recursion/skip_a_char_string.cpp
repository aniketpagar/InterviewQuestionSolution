/****************************************************************************
File name: skip_a_char_string.cpp

Author: babajr
*****************************************************************************/


/*
Given a string. Write a program to remove all the occurrences of a character
in the string.

Input : s = "geeksforgeeks"
        c = 'e'
Output : s = "gksforgks"
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to skip the character from the string and return new string.
Algoithm:
--> Get the string str and character X for which character X is to be removed.
--> Recursively iterate for all the character in the string:
    --> Base Case: If the length of the string str called recursively is 0
        then return the empty string from the function.
        if(str.length()==0) {
           return "";
        }
    --> Recursive Call: If the base case is not met, then check for the character
        at 0th index if it is X then recursively iterate for the substring removing the
        first character.
        if (str[0] == X) {
            return recursive_function(str.substr(1), X);
        }
    --> Return Statement: At each recursive call(except the base case and the above condition),
        return the recursive function for the next iteration including the character at
        0th index.
        return str[0] + recursive_function(str.substr(1), X)
*/
string skip(string str, char x)
{
    // base case
    if(str.length() == 0)
        return "";

    // check the first character of the given string
    if(str[0] == x)
    {
        return skip(str.substr(1), x);
    }

    return str[0] + skip(str.substr(1), x);
}


int main(void)
{
    // string str = "bacacaacc";
    string str = "geeksforgeeks";
    char x = 'e';

    str = skip(str, x);
    cout << str << endl;

    return 0;
}

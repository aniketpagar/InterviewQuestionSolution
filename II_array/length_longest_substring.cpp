/****************************************************************************
File name: length_longest_substring.cpp

Author: babajr
*****************************************************************************/


/*
Length of the longest substring without repeating characters.
Given a string str, find the length of the longest substring without repeating characters.

Input: str[] = ABDEFGABEF

Output: 6 (longest substring are “BDEFGA” and “DEFGAB”)
*/

#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Approach. TC = O(n3)

Idea is to consider all the possible substrings one by one and check whether it contains all
unique characters or not.

Algo:
--> Generate all the substrings.
--> Check for substring with longest length that contains unique characters.
*/
/*
API to check whether substring contains all unique characters or not.
If all unique characters found, it will return 1 else 0.
*/
bool check_unique_char(char str[], int start, int end)
{
    int hash_arr[256] = {0}; // hash array to store informaton if char in str is visited or not.

    for(int i = start; i <= end; i++)
    {
        if(hash_arr[str[i]] == 1) // No distinct characters
            return 0; // False. substring contains no unique characters.

        hash_arr[str[i]] = 1; // True
    }

    return 1; // substtring contains unique characters.
}


int longest_substring_unique_chars(char str[], int len)
{
    int longest_len = 0;

    // generate all possible substrings
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            // for substring (i to j) check whether it contains all
            // unique characters.
            if(check_unique_char(str, i, j) == 1)
                longest_len = max(longest_len, j - i + 1);
        }
    }

    return longest_len;
}


/*
Approach 2: Using Sliding Window. TC = O(n2)

Idea is to have a window of unique characters in the substring. Whenever we see repitition, remove the
previous occurance of the repiting char.
*/
int longest_substring_unique_chars_eff(char str[], int len)
{
    int longest_len = 0;

    // generate all possible substrings
    for(int start = 0; start < len; start++)
    {
        int hash_arr[256] = {0}; // hash array to store informaton if char in str is visited or not.

        for(int end = start; end < len; end++)
        {
            // if current char is already visited, come out of the loop
            if(hash_arr[str[end]] == 1)
            {
                break;
            }
            else // update the longest_len if this window is larger. Also mark the current char as visited.
            {
                longest_len = max(longest_len, end - start + 1);
                hash_arr[str[end]] = 1;
            }
        }

        hash_arr[str[start]]; // remove the first char of previous window.
    }

    return longest_len;
}


int main(void)
{
    char str[] = "AAB";

    int length = strlen(str);

    printf("Length of Longest Substring: %d\n", longest_substring_unique_chars(str, length));
    printf("Length of Longest Substring: %d\n", longest_substring_unique_chars_eff(str, length));

    return 0;
}

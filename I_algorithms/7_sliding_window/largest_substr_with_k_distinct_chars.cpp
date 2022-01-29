/****************************************************************************
File name: largest_substr_with_k_distinct_chars.cpp

Author: babajr
*****************************************************************************/


/*
Given a string, find the length of the longest substring in it
with no more than K distinct characters.

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
*/

#include<bits/stdc++.h>
using namespace std;


/*
Efficient Approach: SLIDING WINDOW.

We will be using unordered_map to keep the track of frequency of each character
we have processed.

Algo:
--> insert characters from the beginning of the string until we have ‘K’ distinct characters
    in the HashMap. These characters will constitute our sliding window. Keep the track of the
    the length of this window as the longest window so far.
--> keep adding one character in the sliding window (i.e. slide the window ahead),
    in a stepwise fashion.
--> In each step, try to shrink the window from the beginning if the count of distinct characters
    in the HashMap is larger than ‘K’.
    shrink the window until we have no more than ‘K’ distinct characters in the HashMap.
--> While shrinking, decrement the frequency of the character going out of the window
    and remove it from the HashMap if its frequency becomes zero.
--> At the end of each step, check if the current window length is the longest so far, and if so,
    remember its length.
*/
int find_largest_substr_with_k_unique_char1(const string &str, int k)
{
    int window_start = 0, max_length = 0;
    unordered_map<char, int> freq_map;

    // try to extend the range [window_start, window_end]
    for (int window_end = 0; window_end < str.length(); window_end++)
    {
        // update the map by adding current character in the map.
        char rightChar = str[window_end];
        freq_map[rightChar]++;

        // shrink the sliding window, until we are left with 'k' distinct characters
        // in the frequency map.
        while ((int)freq_map.size() > k)
        {
            // for shrinking the sliding window remove char at window_start.
            char leftChar = str[window_start];
            freq_map[leftChar]--;

            // if char count becomes 0, erase it from the map.
            if (freq_map[leftChar] == 0)
            {
                freq_map.erase(leftChar);
            }

            // shrink the window
            window_start++;
        }

        // remember the maximum length so far
        max_length = max(max_length, window_end - window_start + 1);
    }

    return max_length;
}


/*
SLIDING WINDOW. Instead of hashmap we will use array.
*/
int find_largest_substr_with_k_unique_char(const string &str, int k)
{
    int window_start = 0, max_len = 0;
    int counter = 0;
    int window_end = 0;

    int hash[128] = {0};

    while(window_end < str.size())
    {
        if(hash[str[window_end]] == 0)
            counter++;

        hash[str[window_end]]++;
        window_end++;

        while(counter > k)
        {
            if(hash[str[window_start]] == 1)
                counter--;

            hash[str[window_start]]--;
            window_start++;
        }

        max_len = max(max_len, window_end - window_start);
    }

    return max_len;
}


int main(int argc, char *argv[])
{
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char("araaci", 2) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char1("araaci", 2) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char("araaci", 1) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char1("araaci", 1) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char("cbbebi", 3) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char1("cbbebi", 3) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char("abcdffaa", 2) << endl;
    cout << "Length of the longest substring: " << find_largest_substr_with_k_unique_char1("abcdffaa", 2) << endl;

    return 0;
}

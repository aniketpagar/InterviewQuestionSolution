/*
For most substring problem, we are given a string and need to find a substring of
it which satisfy some restrictions.
A general way is to use a hashmap assisted with two pointers. The template is given below.
*/

#include<bits/stdc++.h>
using namespace std;


/*
API to get the length of Longest Substring with At Most K Distinct Characters.
*/
int find_largest_substr_with_k_unique_char(char *str, int k)
{
    int max_len = 0;
    int window_start = 0;
    int window_end = 0;
    int counter = 0; // to keep the track of unique characters in the array.
    int map[128] = {0}; // array to keep the count of characters from the input array.

    while(window_end < strlen(str))
    {
        // increment counter if the char is distinct.
        if(map[str[window_end]] == 0)
            counter++;

        // add the char at current index to the map and increment the index.
        map[str[window_end]]++;
        window_end++;

        // do above only until distinct char are < k.
        while(counter > k)
        {
            // decrement the counter for the unique character if found
            if(map[str[window_start]] == 1)
                counter--;

            // shrink the sliding window:
            // remove the char from the map array.
            // also, increment the window_start.
            map[str[window_start]]--;
            window_start++;
        }

        max_len = max(max_len, window_end - window_start);
    }


    return max_len;
}


/*
API to get the length of Longest Substring with At Most 2 Distinct Characters.
Code and logic is same as above, just replace k with 2.
*/
int find_largest_substr_with_atmost_2_unique_char(char *str)
{
    int max_len = 0;
    int counter = 0;
    int window_end = 0;
    int window_start = 0;

    int map[128] = {0};

    while(window_end < strlen(str))
    {
        if(map[str[window_end]] == 0)
            counter++;

        map[str[window_end]]++;
        window_end++;

        while(counter > 2)
        {
            if(map[str[window_start]] == 1)
                counter--;

            map[str[window_start]]--;
            window_start++;
        }

        max_len = max(max_len, window_end - window_start);
    }

    return max_len;
}


/*
API to get the length of Longest Substring Without Repeating Characters.
*/
int find_largest_substr_without_repeating_char(char *str)
{
    int max_len = 0;
    int counter = 0;
    int window_end = 0;
    int window_start = 0;

    int map[128] = {0};

    while(window_end < strlen(str))
    {
        if(map[str[window_end]] > 0)
            counter++;

        map[str[window_end]]++;
        window_end++;

        while(counter > 0)
        {
            if(map[str[window_start]] > 1)
                counter--;

            map[str[window_start]]--;
            window_start++;
        }

        max_len = max(max_len, window_end - window_start);
    }

    return max_len;

}


int main(void)
{
    char str[] = "aaaaracai";
    cout << "Length of the longest substring with at most k distinct charactrers: "
    << find_largest_substr_with_k_unique_char(str, 3) << endl;

    cout << "Length of the longest substring with at most k distinct charactrers: "
    << find_largest_substr_with_atmost_2_unique_char(str) << endl;

    cout << "Length of the longest substring with at most k distinct charactrers: "
    << find_largest_substr_without_repeating_char(str) << endl;

    return 0;
}

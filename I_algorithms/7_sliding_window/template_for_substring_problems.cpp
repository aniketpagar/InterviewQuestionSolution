/****************************************************************************
File name: template_for_substring_problems.cpp

Author: babajr
*****************************************************************************/


/*
For most substring problem, we are given a string and need to find a substring of
it which satisfy some restrictions.
A general way is to use a hashmap assisted with two pointers. The template is given below.
*/

int findSubstring(string s)
{
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for()
        { /* initialize the hash map here */ }

        while(end < s.size()){

            if(map[s[end++]]-- ?)
            {  /* modify counter here */ }

            while(/* counter condition */)
            {

                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again

                if(map[s[begin++]]++ ?)
                { /*modify counter here*/ }
            }

            /* update d here if finding maximum*/
        }
        return d;
  }

/*
The code of solving Longest Substring with At Most K Distinct Characters is below:
*/
int lengthOfLongestSubstringTwoDistinct(string s, int K)
{
    vector<int> map(128, 0);
    int counter=0, begin=0, end=0, d=0;

    while(end < s.size())
    {
        if(map[s[end++]]++==0)
            counter++;

        while(counter>K)
            if(map[s[begin++]]--==1)
                counter--;

        d=max(d, end-begin);
    }

    return d;
}

/* Simplified Statements */
int lengthOfLongestSubstringTwoDistinct(string s, int K)
{
    vector<int> map(128, 0);
    int counter = 0, begin = 0, end = 0, d = 0;

    while(end < s.size())
    {
        // check if char is not present in the map array.
        // for unique characters increment the counter.
        if(map[s[end]] == 0)
            counter++;

        // add the char to map array and go to next char in the string
        map[s[end]]++;
        end++;

        // shrink the sliding window, until we are left with 'k' distinct characters
        // in the frequency map.
        while(counter > K)
        {
            if(map[s[start]] == 1)
                counter--;

            map[s[start]]--;
            start++; // shrink the window
        }

        d = max(d, end - begin);
    }

    return d;
}

====================================================================================


/*
The code of solving Longest Substring with At Most 2 Distinct Characters is below:
*/
int lengthOfLongestSubstringTwoDistinct(string s)
{
    vector<int> map(128, 0);
    int counter=0, begin=0, end=0, d=0;

    while(end < s.size())
    {
        if(map[s[end++]]++==0)
            counter++;

        while(counter>2)
            if(map[s[begin++]]--==1)
                counter--;

        d=max(d, end-begin);
    }

    return d;
}


/* Simplified Statements */
int lengthOfLongestSubstringTwoDistinct(string s)
{
    vector<int> map(128, 0);
    int counter = 0, begin = 0, end = 0, d = 0;

    while(end < s.size())
    {
        // check if char is not present in the map array.
        // for unique characters increment the counter.
        if(map[s[end]] == 0)
            counter++;

        // add the char to map array and go to next char in the string
        map[s[end]]++;
        end++;

        // shrink the sliding window, until we are left with '2' distinct characters
        // in the frequency map.
        while(counter > 2)
        {
            if(map[s[start]] == 1)
                counter--;

            map[s[start]]--;
            start++; // shrink the window
        }

        d = max(d, end - begin);
    }

    return d;
}

====================================================================================



/*
The code of solving Longest Substring Without Repeating Characters is below:
*/
int lengthOfLongestSubstring(string s)
{
    vector<int> map(128,0);
    int counter=0, begin=0, end=0, d=0;
    while(end<s.size())
    {
        if(map[s[end++]]++>0)
            counter++;

        while(counter>0)
            if(map[s[begin++]]-->1)
                counter--;

        d=max(d, end-begin); //while valid, update d
    }

    return d;
}


/* Simplified Statements */
int lengthOfLongestSubstring(string s)
{
    vector<int> map(128, 0);
    int counter = 0, begin = 0, end = 0, d = 0;

    while(end < s.size())
    {
        // check if char is not present in the map array.
        // for unique characters increment the counter.
        if(map[s[end]] > 0)
            counter++;

        // add the char to map array and go to next char in the string
        map[s[end]]++;
        end++;

        // shrink the sliding window, until we are left with '0' distinct characters
        // in the frequency map.
        while(counter > 0)
        {
            if(map[s[start]] > 1)
                counter--;

            map[s[start]]--;
            start++; // shrink the window
        }

        d = max(d, end - begin);
    }

    return d;
}

====================================================================================


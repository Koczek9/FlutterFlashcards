#include "3_longest_substring.h"

//Given a string s, find the length of the longest
//substring without repeating characters.

int Solution::lengthOfLongestSubstring(string s) 
{
    int result = 0;
    int count = 0;
    deque<char> letters;

    for(int i = 0; i < s.length(); i++)
    {
        if(find(letters.begin(), letters.end(), s[i]) == letters.end())
        {
            letters.push_back(s[i]);
            count += 1;
        }
        else
        {
            if(count > result)
                result = count;

            while(letters.front() != s[i])
            {
                letters.pop_front();
                count --;
            }
            
            letters.pop_front();
            letters.push_back(s[i]);
        }
    }

    if(count > result)
        result = count;

    return result;
};

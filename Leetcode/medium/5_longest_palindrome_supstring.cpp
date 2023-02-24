#include "solution.h"

//Given a string s, return the longest palindromic substring in s.

bool Solution::checkIfPalindrome(string a)
{
    for(int i = 0; i < a.length() / 2; i++)
    {
        if(a[i] != a[a.length() - i - 1])
            return false;
    }

    return true;
}

string Solution::longestPalindrome(string s)
{
    string result = "";

    if(s.length() <= 1)
        return s;

    for(int i = 0; i < s.length() - 1; i++)
    {
        int charPair = s.find_last_of(s[i]);
        string temp = s.substr(i, charPair - i + 1);
        while(charPair != i && temp.length() > result.length())
        {
            if(checkIfPalindrome(temp))
                result = temp;
            else
            {
                charPair = temp.find_last_of(s[i], temp.length() - 2);
                temp = temp.substr(0, charPair + 1);
            }
        }
    }

    if(result.empty())
        return s.substr(0,1);

    return result;
}

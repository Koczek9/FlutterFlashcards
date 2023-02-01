# include <iostream>

// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(std::string s) {

        int result = 0;

        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                if(i == 0)
                {
                    result += 1;
                    continue;
                }
                else if(s[i - 1] == ' ')
                {
                    result += 1;
                    break;
                }
                result += 1;
            }
        }

        return result;
    }
};
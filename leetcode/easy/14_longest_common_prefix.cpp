#include <iostream>
#include <vector>

//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        std::string common_prefix = "";
        std::string shortest_word = strs[0];
        bool common_letter = true;

        for(int i = 0; i < strs.size(); i++)
        {
            if(shortest_word.size() > strs[i].size())
            {
                shortest_word = strs[i];
            }
        }

        for(int i = 0; i < shortest_word.size() && common_letter; i++)
        {
            for(int j = 0; j < strs.size(); j++)
            {
                if(shortest_word[i] != strs[j][i])
                {
                    common_letter = false;
                    break;
                }
            }
            if(common_letter)
            {
                common_prefix += (shortest_word[i]);
            }
        }
        return common_prefix;
    }
};
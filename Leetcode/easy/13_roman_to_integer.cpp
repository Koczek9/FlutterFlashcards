# include <iostream>
#include <unordered_map>

//Given a roman numeral, convert it to an integer.

class Solution {
public:
    int romanToInt(std::string s)
    {
        int integer_number = 0;
        std::unordered_map<char, int> roman_symbols
        {{'I',1},{'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        for(int i = 0; i < s.size(); i++)
        {
            if(roman_symbols[s[i]] < roman_symbols[s[i + 1]])
            {
                integer_number -= roman_symbols[s[i]];
            }
            else
            {
                integer_number += roman_symbols[s[i]];
            }
        }
        return integer_number;
    }
};
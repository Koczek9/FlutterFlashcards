#include <vector>

//Given an integer x, return true if x is a palindrome, and false otherwise.
//Could you solve it without converting the integer to a string?

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
        {
            return false;
        }
        if(x <= 9)
        {
            return true;
        }
        
        std::vector<int> digits;
        while(x > 9)
        {
            int digit = x % 10;
            x = x / 10;
            digits.emplace_back(digit);
        }
        digits.emplace_back(x);

        for(int i = 0; i <= digits.size() / 2; i++)
        {
            if(digits[i] != digits[digits.size() - 1 - i])
            {
                return false;
            }
        }

	return true;
    }
};
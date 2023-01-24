#include <stack>
#include <unordered_map>
#include<iostream>

//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:
    //Open brackets must be closed by the same type of brackets.
    //Open brackets must be closed in the correct order.
    //Every close bracket has a corresponding open bracket of the same type.


class Solution {
public:
    bool isValid(std::string s) 
    {
        if(s.size() % 2 != 0)
        {
            return false;
        }

        std::unordered_map<char, char> parantheses
        {{'(',')'}, {'[',']'}, {'{','}'}};
        
        std::stack<char> stack_of_parantheses;

        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack_of_parantheses.push(parantheses[s[i]]);
            }
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stack_of_parantheses.empty())
                    return false;
                if(stack_of_parantheses.top() != s[i])
                    return false;
                
                stack_of_parantheses.pop();
            }
        }
        if(!stack_of_parantheses.empty())
            return false;
        
        return true;
    }
};
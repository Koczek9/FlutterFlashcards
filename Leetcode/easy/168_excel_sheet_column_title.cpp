#include<iostream>

//Given an integer columnNumber, return its corresponding column title 
//as it appears in an Excel sheet.

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string result = "";

        int lettersInAlphabet = 'Z' - 'A' + 1;

        while(columnNumber > 0)
        {
            int letterAsNumber = columnNumber % lettersInAlphabet;
            if (letterAsNumber == 0)
            {
                letterAsNumber = lettersInAlphabet;
            }          

            result = char(letterAsNumber + 'A' - 1) + result;
            columnNumber = (columnNumber - letterAsNumber) / lettersInAlphabet;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    
    cout << solution.convertToTitle(701) << endl;

    return 0;
}
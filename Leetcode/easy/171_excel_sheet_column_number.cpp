#include<iostream>
#include<math.h>

//Given a string columnTitle that represents the column title 
//as appears in an Excel sheet, return its corresponding column number.

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        
        int numberOfLetters = 'Z' - 'A' + 1;
        int j = 0;

        for(int i = columnTitle.length() - 1; i >=0; i--)
        {
            result += (columnTitle[i] - 'A' + 1) * pow(numberOfLetters, j);
            j++;
        }

        return result;
    }
};
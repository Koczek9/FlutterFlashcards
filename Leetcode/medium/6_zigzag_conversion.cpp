#include "solution.h"

//The string "PAYPALISHIRING" is written in a zigzag pattern
//on a given number of rows like this: (you may want to display
//this pattern in a fixed font for better legibility)

//P   A   H   N
//A P L S I I G
//Y   I   R

//P     I    N
//A   L S  I G
//Y A   H R
//P     I

string Solution::convert(string s, int numRows)
{
    string result = "";
    vector<string> dividedStrings;

    if(numRows <= 1)
        return s;

    dividedStrings.resize(numRows);
    int direction = -1;
    int vectorIndex = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(i % (numRows - 1) == 0)
        {
            direction *= -1;
        }

        dividedStrings[vectorIndex] = dividedStrings[vectorIndex] + s[i];
        vectorIndex += direction;
    }

    for(int i = 0; i < numRows; i++)
    {
        result = result + dividedStrings[i];
    }

    return result;
}

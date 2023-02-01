//Given a non-negative integer x, return the square root of x 
//rounded down to the nearest integer. The returned integer should be non-negative as well.
//You must not use any built-in exponent function or operator.

class Solution {
public:
    int mySqrt(int x) {

        if(x < 1)
        {
            return 0;
        }

        int result = 1;

        for(; result <= x / result; result++)
        {
            if(result == x / result)
            {
                return result;
            }
        }

        return result - 1;    
    }
};
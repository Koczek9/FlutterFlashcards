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

        int min = 1;
        int max = x;
        int mid = 1;
        int result;

        while(min <= max)
        {
            mid = min + (max - min) / 2;
            if(mid == x / mid)
            {
                return mid;
            }
            else if(mid < x / mid)
            {
                min = mid + 1;
                result = mid;
            }
            else
            {
                max = mid - 1;
            }
        }
        
        return result;
    }
};
//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:

    int climbStairs(int n) 
    {
        int result = 1;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int previous = 1;
        result = 2;

        for (int i = 2; i < n; i++)
        {
            int tmp = result;
            result = previous + result;
            previous = tmp;
        }
        
        return result;
    }
};
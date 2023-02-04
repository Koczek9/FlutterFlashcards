//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//Using combination formula.

#include <iostream>
#include<math.h>

class Solution {
public:
    double countPossibilities(int numberOfSteps, int numberOfDoubleSteps)
    {
        double possibilities = 1;

        for(int i = 0; i < numberOfDoubleSteps; i++)
        {
            double temp = (numberOfSteps - i) / (double) (i + 1);
            possibilities *= temp;
        }

        return possibilities;
    }

    int climbStairs(int n) 
    {
        int result = 1;
        int numberOfSteps;
        int numberOfDoubleSteps = 1;
        int maxNumberOfDoubleSteps = n / 2;

        while(numberOfDoubleSteps <= maxNumberOfDoubleSteps)
        {
            numberOfSteps = n - numberOfDoubleSteps;
            result += countPossibilities(numberOfSteps, numberOfDoubleSteps);
            //std::cout << countPossibilities(numberOfSteps, numberOfDoubleSteps) << std::endl;
            numberOfDoubleSteps ++;
        }
        
        return result;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.climbStairs(35) << std::endl;
}
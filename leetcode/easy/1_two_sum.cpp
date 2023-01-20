#include <iostream>
#include <vector>

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        int array_length = nums.size();
        std::vector<int> result;
        bool found = false;
        for(int i = 0; i < array_length - 1 && ! found; i++)
        {
            for(int j = i + 1; j < array_length; j++)
            {
                if(nums[i] + nums[j] == target && i != j)
                {
                    result.emplace_back(i);
                    result.emplace_back(j);
                    found = true;
                    break;
                }
            }
        }
        return result;
    }
};
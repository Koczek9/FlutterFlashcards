#include <vector>

//Given an integer array nums sorted in non-decreasing order, 
//remove the duplicates in-place such that each unique element appears only once. 
//The relative order of the elements should be kept the same.
//Return k - number of left elements.

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        if(nums.empty())
        {
            return 0;
        }

        if(nums.size() == 1)
        {
            return nums.size();
        }

        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        
        return nums.size();
    }
};
#include<stdint.h>

// Write a function that takes the binary representation 
//of an unsigned integer and returns the number of '1' bits it has 
//(also known as the Hamming weight).

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int result = 0;

        while(n != 0)
        {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};
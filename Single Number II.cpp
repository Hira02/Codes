/*
Problem Description : (Lc 137)
----------------------------------------------------------
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

Code:
-----------------------------------------------------
//Approach: https://www.youtube.com/watch?v=jO7uGdvGGC4
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int count = 0;
        for(int i = 0 ; i < 32 ; i++){
            count = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if((nums[j] & (1<<i) )!=0)
                    count++;
            }
            result = result | ((count%3)<<i);
        }
        return result;
    }
};

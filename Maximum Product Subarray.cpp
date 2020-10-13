/*
Problem Description : (LC 152)
--------------------------------------------------------------------------------------------------
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*///Code:
//---------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() ==0){
            return 0;
        }
       
        int max_ = nums[0];
        int min_ = nums[0];
         int res = max_;
        for(int i = 1 ; i<nums.size() ; i++){
           if(nums[i]<0){
               swap(max_, min_);
           }
            max_ = max(nums[i], nums[i]*max_);
            min_ = min(nums[i], nums[i]*min_);
             res= max(max_, res);
        }
       
        
        return res;
    }
};
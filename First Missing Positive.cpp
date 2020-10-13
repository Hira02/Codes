/*
Problem Description : (LC 41)
-----------------------------------------------------------------------------
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.
*/
//Code:
-----------------------------------------------------------------------------------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //the answer must be between 1 to n else n+1
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i] = n+1; //making them discarded 
        }
        for(int i = 0 ; i < n ; i++){
            int num = abs(nums[i]);
            if(num>n)
                continue;
            num--;
            if(nums[num]>0)
                nums[num] = -1*nums[num];
        }
        for(int i = 0 ; i < n ; i++){
            if(nums[i]>=0)
                return i+1;
        }
        return n+1;
    }
};
//full explanation : https://leetcode.com/problems/first-missing-positive/discuss/319270/Explanation-of-crucial-observation-needed-to-deduce-algorithm
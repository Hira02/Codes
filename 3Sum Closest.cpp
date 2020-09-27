/*
Problem Description : (LC 16)
------------------------------------------------------------------------------
Given an array nums of n integers and an integer target, find three integers in nums such that the sum 
is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/
//Code:
//-------------------------------------------------------------------------------------------
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < size && diff!= 0 ; i++){
            int lo = i+1;
            int high = size-1;
            while(lo< high){
                int sum = nums[i]+nums[lo]+nums[high];
                if(abs(target - sum)<abs(diff)){
                    diff = target - sum;
                }
                if(sum<target){
                    lo++;
                }else{
                    high--;
                }
            }
        }
        return target - diff;
    }
};
/*
Problem Description : (LC 312)
--------------------------------------------------------------------------------------------------------
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums.
 You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i.
After the burst, the left and right then becomes adjacent.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 500
0 <= nums[i] <= 100
*/
//Code:
//----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int len = n+2;
        vector<int> arr = {1};
        for(auto& num : nums)
            arr.push_back(num);
        arr.push_back(1);
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int gap = 2; gap < len; gap++) {
            for(int left = 0; left < len-gap; left++) {
                int right = left+gap;
                int cur = 0;
                for(int mid = left+1; mid < right; mid++) {
                    cur = max(cur, dp[left][mid]+dp[mid][right]+arr[left]*arr[mid]*arr[right]);
                }
                dp[left][right] = cur;
            }
        }
        return dp[0][len-1];
    }
};
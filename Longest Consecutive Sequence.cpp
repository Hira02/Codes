/*
Problem Description: (LC 128) HARD
---------------------------------------------------------------------------------
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

Code:
--------------------------------------------------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> Map;
        for(int num : nums){
            Map.insert(num);
        }
        int left = 0, right= 0;
        int Max = (nums.size() == 0)?0:1;
        for(int i = 0 ; i < nums.size() ; i++){
             int currSize = 0;
            if(Map.find(nums[i]-1) == Map.end()){
            right = nums[i];
            while(Map.find(right) != Map.end()){ 
                right++;
            }
            Max = max(Max, right - nums[i]);
            }
        }
        return Max;
    }
};
//https://www.geeksforgeeks.org/longest-consecutive-subsequence/
//TC : O(n)
//SC : O(n)

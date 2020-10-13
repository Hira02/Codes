/*
Problem Description : (LC 90)
----------------------------------------------------------------------------------
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//Code:
//---------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void subsets(vector<int>& nums,  vector<vector<int>>& res, vector<int>& set, int start, int end){
        res.push_back(set);
        if(start>end){
            return ;
        }
        for(int i = start ; i<= end ; i++){
            if(i != start && nums[i]== nums[i-1]) continue;
                set.push_back(nums[i]);
                subsets(nums, res, set, i+1, end);
                set.pop_back();
            // }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        subsets(nums,res, temp,0, nums.size()-1);
        return res;
    }
};
//Source : https://leetcode.com/problems/subsets-ii/discuss/30156/Subset-I-II-and-Perm-I-II-Difference-Explained
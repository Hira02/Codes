/*
Problem Description : (LC 40)
----------------------------------------------------------------------------------------------
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
//Code:
//-------------------------------------------------------------------------------------------------
class Solution {
public:
     void helper(vector<int>& candidates,vector<vector<int>>& res, vector<int>& temp, int target, int start, int end, int currSum){
        if(currSum == target){
            res.push_back(temp);
            return ;
        }
        if(currSum>target){
            return ;
        }
        for(int i = start ; i<end ; i++){
            if(i>start && candidates[i] == candidates[i-1])// no duplicates
                continue;
            temp.push_back(candidates[i]);
            helper(candidates, res, temp, target, i+1, end, currSum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, temp, target, 0, candidates.size(), 0);
        return res;
    }
};
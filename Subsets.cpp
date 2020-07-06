Problem Description : (LC 78)
--------------------------------------------------------------------
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

Code:
-------------------------------------------------------------------------------
class Solution {
public:
    void getAllSubset(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int index){
        ans.push_back(subset);
        for(int i = index ; i<nums.size() ; i++){
            subset.push_back(nums[i]);
            getAllSubset(nums, ans, subset, i+1);
            subset.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        getAllSubset(nums, ans, subset, 0);
        return ans;
        
    }
};

//TC : O(2^n) // for every i two recursion occurs

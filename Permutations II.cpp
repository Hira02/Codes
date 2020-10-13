/*
Problem Description : (LC 47)
---------------------------------------------------------------------------------------
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
//Code:
//---------------------------------------------------------------------------------
class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int ,int>& Map, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return ;
        }
        for(auto &t : Map){ // remember to take "&t" not "t"
            if(t.second <= 0) continue;
            t.second--;
            temp.push_back(t.first);
            helper(nums, Map, temp, res);
            t.second++;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int ,int> Map;
        for(int i= 0 ; i < nums.size() ; i++){
            Map[nums[i]]++;
        }
        helper(nums, Map, temp, res);
        return res;
    }
};
//Source :https://leetcode.com/problems/subsets-ii/discuss/30156/Subset-I-II-and-Perm-I-II-Difference-Explained
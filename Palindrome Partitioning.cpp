/*
Problem Description : (LC 131)
-----------------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
//Code: Leetcode Sol. (Backtracking + dynamic programming)
//----------------------------------------------------------------------------------------------
class Solution {
public:
    void helper(string s, vector<vector<string>>& res,  vector<vector<bool>>& dp, vector<string>& temp, int start){
        if(start>= s.size()){
            res.push_back(temp);
            return ;
        }
        for(int end = start ; end<s.size() ; end++){
            if(s[start] == s[end] &&(end-start<=2 || dp[start+1][end-1])){
                dp[start][end] = true;
                temp.push_back(s.substr(start, end-start+1));
                helper(s, res, dp, temp, end+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<string>> res;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<string> temp;
        helper(s, res, dp, temp, 0);
        return res;
    }
};
//TC : O(2^n)
//SC : O(n*n)+O(n) : dp array + recursion stack
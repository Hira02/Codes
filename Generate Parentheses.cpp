/*
Problem Description : (LC 22)
-----------------------------------------------------------------------------------------------
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//Code:
//-------------------------------------------------------------------------------------------------
class Solution {
public:
    void helper(string res, vector<string>& ans, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(res);
             return ;
        }
           if(left>0) helper(res+'(', ans, left-1, right);
            if(right>left) helper(res + ')', ans, left, right-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> Res;
        helper("", Res, n, n);
        return Res;
    }
};
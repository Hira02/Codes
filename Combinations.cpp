/*
Problem Description  : (LC 77)
----------------------------------------------------------------------------
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/
//Code:
//---------------------------------------------------------------------------------
class Solution {
public:
    void helper(int start, int end, int k,vector<vector<int>>& res, vector<int>& temp, int currCount ){
        if(currCount == k){
            res.push_back(temp);
            return ;
        }
        for(int i = start ; i<=end ; i++){
            temp.push_back(i);
            helper(i+1, end, k, res, temp, currCount+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(1, n, k, res, temp, 0);
        return res;
    }
};
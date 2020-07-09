/*
Problem Description : (LC 119)
------------------------------------------------------------
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
Input: 3
Output: [1,3,3,1]
*/
Code:
------------------------------------------------------------------------
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,0);
        ans[0] =1;
        for(int i = 1; i <= rowIndex ; i++){
            for(int j = i; j >= 1; j--){
                ans[j] = ans[j] + ans[j-1];
            }
        }
        return ans;
    }
};

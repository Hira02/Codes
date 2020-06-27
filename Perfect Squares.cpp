/*

Problem Description : (LC 279)
-----------------------------------------------------------------------------------------------
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

Code:
----------------------------------------------------------------------------------------------------
class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1,n);
        ans[0] = 0;
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j*j<=i ; j++){
                ans[i] = min(ans[i-j*j]+1,ans[i]);
            }
        }
        return ans[n];
        
    }
};

//Approach : https://www.youtube.com/watch?v=o2IBfabt8qM

/*
Problem Description : (LC 132) HARD
--------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/
//Code: 
//------------------------------------------------------------------------------------
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> minCut(n+1);
        for(int i = 0 ; i <= n ; i++){
            minCut[i] = i-1;// as each character is palindrom itself
        }
        for(int i = 1; i <n ; i++){
            for(int j = i ; j>=0 ; j--){
                if(s[i] == s[j]  &&(i-j<=2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    minCut[i+1] = min(minCut[i+1], 1+minCut[j]);
                }
            }
        }
        return minCut[n];
    }
};
//Ref : https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42212/Two-C%2B%2B-versions-given-(one-DP-28ms-one-Manancher-like-algorithm-10-ms)
/*
Problem Description : (LC 139)
------------------------------------------------------------------------------------------------------
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of 
one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

Code:
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool helper(string s, unordered_set<string>& dict){
        if(s.length() == 0)
            return true;
       bool dp[s.length()+1] ;
        memset(dp, 0, sizeof(dp));        
        for(int i = 1 ; i<=s.length() ; i++){
            string temp = s.substr(0,i);
           if(dp[i] == false && dict.count(temp) )
               dp[i] = true;
           if(dp[i] == true){
               if(i == s.length())
                   return true;
               for(int j = i+1 ; j<= s.length()  ; j++){
                   if(dp[j] == false && dict.count(s.substr(i,j-i)))
                       dp[j] = true;
                   if(j == s.length() && dp[j] == true)
                       return true;
               }
           }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int max_len = 0;
        for(auto a : wordDict){
            dict.insert(a);
            max_len = max(max_len, (int)a.length());
        }
        return helper(s, dict);
    }
};

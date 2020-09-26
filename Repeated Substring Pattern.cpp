/*
Problem Description : (LC 459)
----------------------------------------------------------------------------------------------
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple 
copies of the substring together. You may assume the given string consists of lowercase English letters only 
and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
//Code:
//------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void computeLPSArray(string str, int M, int lps[]) 
{ 
    int len = 0; 
    int i;   
    lps[0] = 0;
    i = 1; 
    while (i < M) 
    { 
       if (str[i] == str[len]) 
       { 
           len++; 
           lps[i] = len; 
           i++; 
       } 
       else 
       { 
          if (len != 0) 
          { 
             len = lps[len-1]; 
          } 
          else
          { 
             lps[i] = 0; 
             i++; 
          } 
       } 
    } 
} 
  
    bool repeatedSubstringPattern(string str) {
    int n =str.length(); 
    int lps[n]; 
    computeLPSArray(str, n, lps); 
    int len = lps[n-1];  
    return (len > 0 && n%(n-len) == 0)? true: false; 
    }
};
/*
Problem Description : (Lc 5)
---------------------------------------------------------------------------------------------------
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

//Code:
//-----------------------------------------------------------------------------------------------------
class Solution {
public:
    int expandFromMiddle(string s, int left, int right){
        if(s == "" || left>right)
            return 0;
        while(left>=0 && right<s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return (right-left -1);
    }
    string longestPalindrome(string s) {
        if(s.size()<1)
            return s;
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int len1 = expandFromMiddle(s, i, i); // for odd
            int len2 = expandFromMiddle(s, i, i+1); // for even
            int len = max(len1, len2);
            if(len>(end-start)){
                start = i - (len-1)/2;
                end = i+(len)/2;
            }
        }
        return s.substr(start, end -start +1);
    }
};
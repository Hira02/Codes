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
#1 :
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

#2 : Faster
class Solution {
public:
    string longestPalindrome(string s) {
        // int len = 0;
        int start = 0;
        int end = 0;
        int k = 0;
        int len = s.length();
        int maxLen = 0;
        string res = "";
        while(k<len){
            start = k;
            end = k;
            while(start>=1 && s[start-1] == s[k])
                start--;
            while(end<len-1 && s[end+1] == s[k])
                end++;
            int updated_k = end+1;
            while(start>=1 && end<len-1 && (s[start-1] == s[end+1]))
            {
                start--;
                end++;
            }
            if(maxLen<(end-start+1)){
                maxLen = end-start+1;
                res = s.substr(start, maxLen);
            }
            k = updated_k;
            
        }
        return res;
    }
};

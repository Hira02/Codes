/*
Problem Description : (LC 32)
-------------------------------------------------------------------------------------
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
 parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
//Code:
//--------------------------------------------------------------------------------------------
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right=  0;
        int maxLen = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                left ++;
            }else{
                right++;
            }
            if(left == right){
                maxLen= max(maxLen, right*2);
            }
            if(right>left){
                right=0;
                left = 0;
            }
        }
         right=0;
         left = 0;
        for(int i = s.length()-1 ; i>=0 ; i--){
            if(s[i] == '('){
                left ++;
            }else{
                right++;
            }
            if(left == right){
                maxLen= max(maxLen, left*2);
            }
            if(right<left){
                right=0;
                left = 0;
            }
        }
        return maxLen;
    }
};
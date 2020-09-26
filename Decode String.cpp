/*
Problem Description : (LC 394)
---------------------------------------------------------------------------------------------------
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for 
those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/
//Code:
//------------------------------------------------------------------------------------------------
class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> digits;
        string res = "";
        // int i = 0 ;
        int num = 0;
        for(int i = 0 ; i<s.length() ; i++){
            if(isdigit(s[i])){
                num = num*10 + s[i]-'0';
            }else if(isalpha(s[i])){
                res.push_back(s[i]);
            }else if(s[i] == '['){
                chars.push(res);
                digits.push(num);
                res = "";
                num = 0;
            }else{
                string temp = "";
                for(int i = 0 ; i < digits.top() ; i++){
                    temp = temp+res;
                }
                res = chars.top()+temp;
                chars.pop();
                digits.pop();
            }
        }
        return res;
    }
};
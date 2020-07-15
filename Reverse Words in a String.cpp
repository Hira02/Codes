/*
Problem Description : (LC 151)
----------------------------------------------------------------------------
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/
Code:
----------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string reverseWords(string s) {
       // "_____!___@__blue__.__is__sky!____"
        int n = s.length();
        int i = 0 , j = 0 ;
        while(j<n){
            while(j<n && s[j] == ' '){
                j++;
            }
            if(i>0 && j<n){
                s[i++] = ' ';
            }
            int start = i;
            while(j<n && s[j] != ' ')
            s[i++] = s[j++];//i= 1
            reverse(s.begin()+start, s.begin()+i);
            
        }
        s.resize(i);
        reverse(s.begin(), s.end());
        return s;
        
    }
};

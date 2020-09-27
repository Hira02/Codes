/*
Probelem Description : (LC 58)
-------------------------------------------------------------------------------------------
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
//Code:
//----------------------------------------------------------------------------------------
class Solution {
public:
    int lengthOfLastWord(string s) {
       int i = s.length()-1;
        int len = 0;
        while(i>-1 && s[i] == ' '){
            i--;
        }
        while(i>-1 && s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};
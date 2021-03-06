/*
Problem Description : (LC 120)
------------------------------------------------------------------------
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

*/
class Solution {
public:
    bool isPalindrome(string s) {
        
      int front = 0;
        int end = s.length() - 1;
        while(front < end){
            while(front<end && !isalnum(s[front]))
                front++;
            while(front<end && !isalnum(s[end]))
                end--;
            if(tolower(s[front]) !=tolower(s[end]))
                return false;
            front++;
            end--;
        }
        return true;
    }
};
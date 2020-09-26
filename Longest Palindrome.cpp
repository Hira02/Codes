/*
Problem Description : (LC 409)
----------------------------------------------------------------------------------
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
//Code:
//---------------------------------------------------------------------------------
class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        unordered_set<char> Set;
        for(int i = 0 ; i < s.length() ; i++){
            if(Set.find(s[i]) != Set.end()){
                Set.erase(s[i]);
                count++;
            }else{
                Set.insert(s[i]);
            }
        }
        return (Set.size() == 0)?count*2:count*2+1;
        
    }
};
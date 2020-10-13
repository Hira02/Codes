/*
Problem Description : (LC 242)
--------------------------------------------------------------------------------------------
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
//Code:
//-----------------------------------------------------------------------------------------------
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> Map;// do not take fixed size of array of 26, because if the i/p is
        // unicode then it won't be able to store those characters
        for(int i = 0 ; i < s.length() ; i++){
            Map[s[i]]++;
        }
        for(int i = 0 ; i < t.size() ; i++){
            if(Map.find(t[i]) != Map.end()){
            Map[t[i]]--;
            if(Map[t[i]] == 0)
                Map.erase(t[i]);
            }else{
                return false;
            }
        }
        return Map.size() == 0;
    }
};
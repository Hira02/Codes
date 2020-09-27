/*
Problem Description : (LC 316)
-------------------------------------------------------------------------------------
Given a string which contains only lowercase letters, remove duplicate letters so that every 
letter appears once and only once. You must make sure your result is the smallest in lexicographical 
order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"
Example 2:

Input: "cbacdcbc"
Output: "acdb"
Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/
//Code:
//-------------------------------------------------------------------------------------------
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> chars(256,0);
        vector<int> visited(256, 0);
        string res = "0";
        for(int i = 0 ; i < s.length() ; i++){
            chars[s[i]]++;
        }
        for(int i = 0 ; i < s.length() ; i++){
            chars[s[i]]--;
            if(visited[s[i]])
                continue;
            while(s[i]<res.back() && chars[res.back()]>0){
                // cout<<s[i]<<" "<<res.back()<<"\n";
                visited[res.back()] = 0;
                res.pop_back();
            }
            res+=s[i];
            visited[s[i]] = 1;
        }
        return res.substr(1);
    }
};
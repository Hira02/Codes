/*
Problem Description  : (LC 392)
---------------------------------------------------------------------
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, 
how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.

*/
Code:
------------------------------------------------------------------------------------
 #1
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return true;
        int index = 0;
        for(int i=0;i<t.length();i++){
            if(t[i] == s[index]){
                index++;
            }
            if(index>=s.length())
                return true;
        }
        return false;
    }
};

#2: for follow up question

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> Map;
        for(int i = 0 ; i < t.length() ; i++){
            Map[t[i]].push_back(i);
        }
        int prev = -1;
        int count = 0;
        for(int i = 0 ; i < s.length() ; i++){
            auto it = Map.find(s[i]);
            if(it == Map.end())
                return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev)- vec.begin();
            if(pos == vec.size())
                return false;
            prev = vec[pos];
            /*
            for(int j = 0 ; j < Map[s[i]].size() ; j++){
               if(Map[s[i]][j]>prev){
                    prev = Map[s[i]][j];
                   count++;
                   break;
               }           
            }
            */
        }
        return true;
    }
               
};

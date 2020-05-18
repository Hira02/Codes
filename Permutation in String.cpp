/*
Problem Description: (LC 567)
------------------------------------------------------------
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].


*/
Code:
---------------------------------------------------------------------
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> s1_(26, 0);
        for(char &c : s1) {
            s1_[c - 'a'] += 1;
        }
        vector<int> s2_(26, 0);
        for(int end = s1.size()-1; end < s2.size(); ++end){
            int start = end - s1.size() + 1;
            if(end == s1.size()-1) {
                while(start <= end) {
                    s2_[s2[start++] - 'a'] += 1;
                }
                if(helper(s1_, s2_)) {
                    return true;
                }
            } 
            else {
                cout<<s2[end]<<" ";
                s2_[s2[end] - 'a'] += 1;
                s2_[s2[start-1] - 'a'] -= 1;
                if(helper(s1_, s2_)) {
                    return true;
                }
            }
        }  
        return false;
    }
private:
    bool helper(vector<int>& s1_, vector<int>& s2_) {
        for(int i = 0; i < 26; ++i) {
            if(s1_[i] != s2_[i]) {
                return false;
            }
        }
        return true;
    }
};

/*
Problem Description:  (LC 438)
------------------------------------
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


*/

Code:
----------------------------------------------------------------------------
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<char> pChars(128, 0);
        int plen = p.length();
        int pCount = 0;
        for(int i = 0 ; i <plen ; i++){
            pChars[p[i]]++;
            if(pChars[p[i]] == 1)
                pCount++;
        }
        int slen  = s.length();
        vector<char> sChars(128, 0);
        int left = 0, right = 0, count = 0;
        while(right<slen){
            sChars[s[right]]++;
            if(pChars[s[right]] == sChars[s[right]])
                count++;
            right++;
            if(right-left>plen){
                if(pChars[s[left]] == sChars[s[left]]){
                    count--;
                }
                 sChars[s[left]]--;
                left++;
               
            }
            if(count == pCount){
                res.push_back(left);
            }
        }
        return res;
    }
};

//TC : O(n) as 128 is constant
//SC  :O(m)+O(n)

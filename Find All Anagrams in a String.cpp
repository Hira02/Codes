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
    int MAX = 256;
    bool compare(vector<char> &v1, vector<char> &v2){
        for(int  i  =  0 ; i<v1.size() ; i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> res;
        if(n==0)
            return res;
        if(m == 0 || m>n){
            return res;
        }
        vector<char> v1(MAX);
        vector<char> v2(MAX);
        for(int  i = 0 ; i < m ; i ++){
            v1[p[i]]++;
            v2[s[i]]++;
        }
        for(int i = m ; i <n ; i++){
            if(compare(v1,v2)){
                res.push_back(i-m);
            }
            v2[s[i]]++;
            v2[s[i-m]]--;
            }
        if(compare(v1,v2)){
            res.push_back(n-m);
        }
        
        return res;
        
    }
};

//TC : O(n) as 256 is constant
//SC  :O(m+n)

/*
Problem Description : (LC 140) HARD
-----------------------------------------------------------------------------------
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
Code:
-----------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<string> helper(string s, unordered_set<string>& dict, unordered_map<int, vector<string>>& Map, int max_len, int start){
        if(Map.count(start))
            return Map[start];
        string str;
        for(int i = start ; i<s.length() && str.length()<max_len ; i++){
            str+=s[i];
            if(dict.count(str)){
                if(i == s.length()-1){
                    Map[start].push_back(str);
                }else{
                    vector<string> temp = helper(s, dict, Map, max_len, i+1);
                    for(auto a: temp){
                        Map[start].push_back(str + " " + a);
                    }
                }
                
            }
        }
        return Map[start];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_map<int, vector<string>> Map;
        int max_len = 0;
        for(auto a : wordDict){
            dict.insert(a);
            max_len = max(max_len, (int)a.length());
        }
        return helper(s, dict, Map, max_len, 0);
        
    }
};

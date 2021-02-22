/*
Problem Description : (LC 524)
---------------------------------------------------------------------------------------------------------------------------------
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. 
If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/
//Code:
//---------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canGenerate(string word, string s){
        int word_i = 0, str_i = 0 ;
        while(word_i<word.length() && str_i < s.length()){
            if(word[word_i] == s[str_i])
                word_i++;
            str_i++;
        }
        return word_i == word.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(auto str: d){
            if(canGenerate(str, s)){
                if(res == "" || (res.length()<str.length()) || (res.length() == str.length() && str<res))
                    res = str;
            }
        }
        return res;
    }
};

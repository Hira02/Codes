/*
Problem Description : (LC 290)
---------------------------------------------------------------------------------------------
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/
//Code:
//--------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<string> createArrayOfWords(string str){
        vector<string> res;
        string s = "";
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == ' '){
                res.push_back(s);
                s = "";
            }else{
                 s+=str[i];               
            }
        }
        res.push_back(s);
        return res;
    }
    bool wordPattern(string pattern, string str) {
        vector<string> strArray = createArrayOfWords(str);
        if(strArray.size()!=pattern.size())
            return false;
        unordered_map<char, string> pat_map;
        unordered_map<string, char> str_map;
        for(int i = 0 ; i <pattern.size() ; i++){
            char c = pattern[i];
            string word = strArray[i];
            if(pat_map.find(c) == pat_map.end()){
                if(str_map.find(word) == str_map.end()){
                    str_map[word] = c;
                    pat_map[c] = word;
                }else{
                    return false;
                }
                
            }else{
                if(pat_map[c] != word)
                    return false;
            }
        }
        return true;
    }
};
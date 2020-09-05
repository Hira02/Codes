/*
Problem Description : (LC 17)
--------------------------------------------------------------------------------------------------
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
//Code:
//------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<char>> arr = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    void helper(vector<string>& ans, string str, int start,  string digits){
        if(start == digits.length()){
            ans.push_back(str);
            return ;
        }
        vector<char> holder = arr[(digits[start]-'0')-2];
        for(int i = 0 ; i < holder.size() ; i++){         
            str.push_back(holder[i]);
            helper(ans, str, start+1,digits);
             str.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.length();
        if(n == 0)
            return res;
        helper(res, "", 0,  digits);
        return res;
    }
};
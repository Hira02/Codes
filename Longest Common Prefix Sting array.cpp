/*
Problem Descrtiption : (LC 14)
-------------------------------------------------------------------------------------
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
//Code:
//---------------------------------------------------------------------------------------
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        for(int i = 0 ; i < strs[0].size() ; i++){
            char c = strs[0][i];
            for(int j = 1 ; j<strs.size() ; j++){
                if(i == strs[j].size() || c != strs[j][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
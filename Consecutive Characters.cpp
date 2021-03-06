/*
Problem Description : (LC 1446)
-------------------------------------------------------------------------------------------------
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
*/
//Code:
//---------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxPower(string s) {
        int max_ = 1;
        int i = 0;
        while(i < s.length()-1){
            int count = 1;
            for(int j = i+1 ; j<s.length() ; j++){
                // cout<<s[i]<<" "<<s[j]<<"\n";
                if(s[i] == s[j]){
                    count++;
                    i++;
                }else{
                    i = j;
                    break;
                }
            }
            max_ = max(max_, count);
        }
        return max_;
    }
};
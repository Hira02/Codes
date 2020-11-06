/*
Problem Description : (LC 187)
-----------------------------------------------------------------------------------
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.
*/
//Code:
//-------------------------------------------------------------------------------------------
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> seen;
        int i = 0;
        while(i+10<= s.length()){
            string str = s.substr(i,10);
            i++;
             seen[str]++;
                if(seen[str]==2){
                    res.push_back(str);
                }
            
        }
        return res;
    }
};
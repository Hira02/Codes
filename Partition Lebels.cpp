/*
Problem Description : (LC 763)
------------------------------------------------------------------------------------------------------
A string S of lowercase English letters is given. We want to partition this string into as many parts as
 possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

//Code:
//-------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int Map[26] = {0};
        for(int i = 0 ; i < S.length() ; i++){
            Map[S[i]-'a'] = i;
        }
        vector<int> arr;
        int last = 0;
        int j = 0;
        for(int i = 0 ; i < S.length() ; i++){
            j= max(j, Map[S[i]-'a']);
            if(i == j){
                arr.push_back(i-last+1);
                last = i+1;
            }
        }
        return arr;
    }
};
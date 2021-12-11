/*
Problem Description : (LC 424)
---------------------------------------------------------------------------------------------------------------------------
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
//Aproach:
/*
1. Find longest window with odd charaters
2. if this odd  character count is less of equal to k then that is the ans

how to find "window with odd charaters"
: (windowLenght - same character count)

*/
// Code:
//------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
    public int characterReplacement(String s, int k) {
        
        int len = s.length();
        int start = 0, longestWindow = 1, repeat = 0;
        int cnt[] = new int[26];
        for(int i = 0 ; i < len ; i++){
            cnt[s.charAt(i) - 'A']++;
            repeat = Integer.max(repeat, cnt[s.charAt(i) - 'A']);
            int nonRepeat = (i-start+1)-repeat;   // focus
            if(nonRepeat>k){                        // not while loop as one by one we check potential window
                cnt[s.charAt(start) - 'A']--;       // focus
                start++;
            }else{
                longestWindow = Integer.max(longestWindow, i-start+1);
            }
        }
        return longestWindow;
    }
}
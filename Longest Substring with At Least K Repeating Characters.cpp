/*
Problem Description : (LC 395)
--------------------------------------------------------------------------------------------------------------------------------------
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character
 in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/
//COde:
//------------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int helper(string s, int start, int k, int end)
    {
        vector<int> storage(26, 0);
        for (int i = start; i < end; i++)
        {
            storage[s[i] - 'a']++;
        }
        for (int i = start; i < end; i++)
        {
            // cout<<storage[s[i]-'a']<<"\n";
            if (storage[s[i] - 'a'] < k)
            {
                int midNxt = i + 1;
                while (midNxt < end && storage[s[midNxt] - 'a'] < k)
                    midNxt++;
                int left = helper(s, start, k, i);
                int right = helper(s, midNxt, k, end);
                return max(left, right);
            }
        }
        return end - start;
    }
    int longestSubstring(string s, int k)
    {

        return helper(s, 0, k, s.length());
        // return s.length();
    }
};
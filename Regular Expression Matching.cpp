/*
Problem Description : (LC 10)
-------------------------------------------------------------------------------
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
//Code:
//--------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool isMatch(string text, string pattern)
        int n = text.length();
        int m = pattern.length();
        if (n == 0 && m == 0)
            return true;
        bool dp[n + 1][m + 1];
        dp[0][0] = true;
        for(int i = 1 ; i <= n ; i++){
            dp[i][0] = false;
        }
        for (int i = 1; i <= m; i++)
        {
            if (pattern[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 2];
            }else{
                dp[0][i] = false;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2];
                    if (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1])
                    {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
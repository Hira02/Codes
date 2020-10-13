/*
Problem Description : (LC 859)
-----------------------------------------------------------------------------------------------
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.
*/
//Code:
//--------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        vector<int> count(26, 0);
        int n = A.size();
        int m = B.size();
        if (n != m)
            return false;
        if (A == B)
        {
            for (int i = 0; i < A.size(); i++)
            {
                count[A[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (count[i] >= 2)
                    return true;
            }
        }
        else
        {
            int prev = -1, curr = -1;
            int unqual = 0;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] != B[i])
                {
                    unqual++;
                    if (unqual > 2)
                        return false;
                    prev = curr;
                    curr = i;
                }
            }
            return (unqual == 2 && A[prev] == B[curr] && A[curr] == B[prev]);
        }
        return false;
    }
};
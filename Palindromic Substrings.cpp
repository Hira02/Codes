/*
Problem Description : (LC 647)
----------------------------------------------------------------------------------------------------------
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings
 even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
*/
//Code:
//-------------------------------------------------------------------------------------------------------------
class Solution
{
private:
    int count = 0;

public:
    int getCount()
    {
        return this->count;
    }
    void setCount(int val)
    {
        this->count += val;
    }
    void expand(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && left <= right && s[left] == s[right])
        {
            setCount(1);
            left--;
            right++;
        }
    }
    int countSubstrings(string s)
    {
        //almost same asinding longest palindromic substring
        if (s.length() == 0)
            return 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            expand(s, i, i);
            // cout<<getCount()<<"\n";
            expand(s, i, i + 1);
        }
        return getCount();
    }
};
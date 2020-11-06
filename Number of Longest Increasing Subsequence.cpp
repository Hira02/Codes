/*
Problem Description : (LC 673)
----------------------------------------------------------------------------
Given an integer array nums, return the number of longest increasing subsequences.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

Constraints:

0 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/
//Code:
//----------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int maxLen = 1;
        vector<int> lisLen(n, 1);
        vector<int> lisCount(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (lisLen[j] + 1 > lisLen[i])
                    {
                        lisLen[i] = lisLen[j] + 1;
                        lisCount[i] = lisCount[j];
                    }
                    else if (lisLen[j] + 1 == lisLen[i])
                    {
                        lisCount[i] += lisCount[j];
                    }
                }
            }
            maxLen = max(maxLen, lisLen[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxLen == lisLen[i])
                ans += lisCount[i];
        }
        return ans;
    }
};
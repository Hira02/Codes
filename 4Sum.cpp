/*
Problem Desdription : (Lc 18)
-------------------------------------------------------------------------------
Given an array nums of n integers and an integer target, are there elements a, b, c, and d 
in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
//Code:
//------------------------------------------------------------------------------------------------------
/*
[1,0,-1,0,-2,2]
[-2,-1,0,0,1,2]
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            while (i > 0 && nums[i] == nums[i - 1])
                i++;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                while (j > i + 1 && nums[j] == nums[j - 1])
                    j++;
                int low = j + 1;
                int high = nums.size() - 1;
                while (low < high)
                {
                    int sum = nums[i] + nums[j] + nums[low] + nums[high];
                    if (sum == target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        low++;
                        high--;
                        while (low < high && nums[low] == nums[low - 1])
                        {
                            low++;
                        }
                        // moving right pointer to left to skip duplicates
                        while (low < high && nums[high] == nums[high + 1])
                        {
                            high--;
                        }
                    }
                    else if (sum > target)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        return res;
    }
};
/*
Problem Description : (LC 34)
-------------------------------------------------------------------------------------------
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

*/
//Code:
//-------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int findIndex(vector<int> &nums, int target, bool left)
    {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target || (left && nums[mid] == target))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res = {-1, -1};
        int leftIndex = findIndex(nums, target, true);
        if (leftIndex == nums.size() || nums[leftIndex] != target)
            return res;
        int rightIndex = findIndex(nums, target, false) - 1;
        res[0] = leftIndex;
        res[1] = rightIndex;
        return res;
    }
};
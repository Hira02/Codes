/*
Problem Description : (LC 81)
-----------------------------------------------------------------------------------------------------
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
//Code:
//-------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[start] == nums[mid] && nums[end] == nums[mid]) // for duplicate values
            {
                start++;
                end--;
            }
            else
            {

                if (nums[mid] >= nums[start])
                {
                    if (target >= nums[start] && target <= nums[mid])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                else
                {
                    if (target >= nums[mid] && target <= nums[end])
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};

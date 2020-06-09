/*
Problem Description : (LC 442)
--------------------------------------------------------------
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

Code:
-----------------------------------------------------------------
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int x = 0;
        for(int i = 0 ; i < nums.size() ; i++){
         if(nums[abs(nums[i])-1]>0)
             nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
            else
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};

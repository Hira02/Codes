/*
Problem Description : (LC 153)
----------------------------------------------------------------------------------------
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
Accepted
496,058
Submissions
1,092,838
*/
//Code:
//--------------------------------------------------------------------------------------
#1:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        if(nums[0]<nums[n])
            return nums[0];
        int left = 0;
        int right = n;
        while(left<right){
            int mid = left + (right - left)/2;
            // cout<<nums[mid]<<" ";
            if((mid-1>=0 && nums[mid] < nums[mid-1]) && (mid+1<=n && nums[mid]<nums[mid+1]))
                return nums[mid];
            else if((mid-1 >= 0 && nums[mid] > nums[mid - 1]) && (mid+1<=n && nums[mid] > nums[mid+1]))
                return nums[mid+1];
            else if(nums[mid]>nums[right])
                left = mid +1;
            else 
                right = mid-1;
        }
        return nums[left];
    }
};

#2:  
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        if(nums[0]<nums[n])
            return nums[0];
        int left = 0;
        int right = n;
        while(left<right){
            int mid = left + (right - left)/2;
            if(nums[mid]<nums[right])
                right = mid;
            else
                left = mid+1;
        }
        return nums[left];
    }
};
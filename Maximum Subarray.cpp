/*
Problem Description : (LC 53)
----------------------------------------------
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
//Approach :1
//Kadane's algo
Code:
-----------------------------------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(currSum>maxSum)
                maxSum = currSum;
            if(currSum <= 0){
                currSum = 0;
            }
        }
        return maxSum;
        
    }
};
//TC : O(n)

//Approach : 2
//Divide & conquer
Code:
---------------------------------------------------------------------
class Solution {
public:
    int crossMax(vector<int>& nums, int l, int mid, int h){
        int leftSum = INT_MIN;
        int leftCurrSum = 0;
        for(int i = mid; i>= l ; i--){
            leftCurrSum+=nums[i];
            if(leftSum<leftCurrSum)
                leftSum = leftCurrSum;
        }
        int rightCurrSum = 0;
        int rightSum = INT_MIN;
        
        for(int i = mid+1 ; i<=h ; i++){
            rightCurrSum+=nums[i];
            rightSum = max(rightSum, rightCurrSum);
        }
        return max(rightSum+leftSum,max(rightSum,leftSum));
    }
    int helper(vector<int>& nums, int l, int h){
        if(l == h)
            return nums[l];
        int mid = l+(h-l)/2;
        return max(max(helper(nums,l, mid), helper(nums, mid+1, h)), crossMax(nums, l, mid, h));
    }
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
        
    }
};
//TC : O(nlogn)

//suggestion : https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/

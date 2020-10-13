/*
Problem Description : (LC 713)
-----------------------------------------------------------------------------------
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/
//Code:
//----------------------------------------------------------------------------------------------------------
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int count = 0;
        int currValue = 1;
       int left = 0;
        int right = 0;
        while(right<nums.size()){
            currValue*=nums[right];
            while(currValue>=k){
                currValue/=nums[left];
                left++;
            }
            count+=(right - left + 1);
            right++;
        }
        return count;
    }
};
/*

Problem Description  : (LC 300)
------------------------------------------------------------------------------------------------------------------------------
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing 
the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/
//Code:
//-----------------------------------------------------------------------------------------------------------
 T(n): O(n^2)
#JAVA
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        int dp[] = new int[len];
        dp[0] = 1;
        for(int i = 1 ; i<len; i++){
            dp[i] = 1;
            for(int j = 0;j<i ; j++){
                if(nums[i]>nums[j]){
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
        }
        int res = dp[0];
        for(int i = 1 ; i<len ; i++){
            // System.out.println(dp[i]);
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}


T(n): O(nlogn)

#JAVA
class Solution {
    int findExactPos(int lis[], int target, int len){
        int low = 0, high = len;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(lis[mid] == target)
                return mid;
            else if(lis[mid]>target){
                high = mid -1;
            }else
                low = mid+1;
        }
        return low;
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int lis[] = new int[n];
        int len = 0;
        lis[len++] = nums[0];
        for(int i = 1 ; i<n ; i++){
            if(nums[i]>lis[len-1]){
                lis[len++] = nums[i];
            }else{
                int pos = findExactPos(lis, nums[i], len-1);
                lis[pos] = nums[i];
            }
        }
        return len;
    }
}
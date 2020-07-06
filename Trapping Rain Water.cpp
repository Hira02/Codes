/*
Problem Description  :(LC 41) HARD
-------------------------------------------------------------------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
Code:
-------------------------------------------------------------------------------------
//Two pinter solution
// we are storing two levels 1. left level and 2. right level
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int leftLevel = 0;
        int rightLevel = 0;
        int left = 0;
        int right  = height.size()-1;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftLevel) leftLevel = height[left];
                res+=leftLevel - height[left];
                left++;
            }else{
                if(height[right]>=rightLevel) rightLevel = height[right];
                res+=rightLevel - height[right];
                right--;
            }
        }
        return res;
    }
};
//TC : O(n)
SC : O(1)

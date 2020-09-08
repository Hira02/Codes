/*
Problem Description : (LC 189)
-------------------------------------------------------------
iven an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
 */
 
 Code:
 ------------------------------------------------------------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n>1){
        int temp2 = nums[0];
        int temp1, processingIndex = 0;
        for(int i = 0 , j=0 ; i < n ; i++){            
            temp1 = temp2;
            processingIndex = (k+processingIndex)%n;
            temp2 = nums[processingIndex];
            nums[processingIndex] = temp1;
            if(processingIndex == j){
                processingIndex = ++j;
                if(processingIndex>n-1)
                    return ;
                temp2 = nums[processingIndex];
            }
        }
        }
    }
};
//https://leetcode.com/problems/rotate-array/discuss/54438/My-c%2B%2B-solution-o(n)time-andand-o(1)space
/*
1,2,3,4,5,6,7    k = 3
5,6,7,1,2,3,4

*/

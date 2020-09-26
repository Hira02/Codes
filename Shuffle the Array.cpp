/*
Problem Descrition : (LC 1470)
--------------------------------------------------
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
*/
Code:
----------------------------------------------------------
 //1:
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n*2);
        int i  = 0;
        int index = 0;
        while(i<n){
            ans[index++] = nums[i];
            ans[index++] = nums[i+n];
            i++;
        }
        return ans;
        
    }
};

//2: in-place   https://leetcode.com/problems/shuffle-the-array/discuss/675007/Python-O(n)-time-O(1)-space-detailed-explanation
class Solution {
public:
    int getDesired(int numIndex, int n){
        return (numIndex<n)?numIndex*2 : (numIndex - n)*2+1;
    }
    vector<int> shuffle(vector<int>& nums, int n) {
    for(int i = 0 ; i < nums.size() ; i++){
        int j = i;
        while(nums[i]>=0){
            j = getDesired(j, n);
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = -temp;
        }
    }
        for(int i = 0 ; i < nums.size() ; i++)
            if(nums[i]<0)
                nums[i] = -nums[i];
        return nums;
    }
};

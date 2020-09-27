/*
Problem Description : (LC 229)
----------------------------------------------------------------------------------------------
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
//Code: https://leetcode.com/problems/majority-element-ii/solution/
//-----------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 =  2147483646, candidate2= 2147483646;
        int count1 = 0, count2 = 0;
        for(auto n : nums){
            if(candidate1 != 2147483646 && candidate1 == n){
                count1++;
            }else if(candidate2 != 2147483646 && candidate2 == n){
                count2 ++;
            }else if(count1 == 0){
                candidate1 = n;
                count1++;
            }else if(count2 == 0){
                candidate2 = n;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto n : nums){
            if(candidate1 != 2147483646 && n == candidate1)
                count1 ++;
            if(candidate2 != 2147483646 && n == candidate2)
                count2++;
        }
        vector<int> result;
        if(count1>nums.size()/3)
            result.push_back(candidate1);
        if(count2>nums.size()/3)
            result.push_back(candidate2);
        return result;
    }
};
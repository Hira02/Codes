/*
Problem Descrption : (LC 260)
-----------------------------------------------------------------------------------------------
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
Code:
-------------------------------------------------------------------------------------------------------------------------------------------
/*
Approach: 
In the first pass, we XOR all elements in the array, and get the XOR of the two numbers we need to find. Note that since the two numbers are distinct,
so there must be a set bit (that is, the bit with value '1') in the XOR result. Find out an arbitrary set bit (for example, the rightmost set bit).

In the second pass, we divide all numbers into two groups, one with the aforementioned bit set, another with the aforementinoed bit unset.
Two different numbers we need to find must fall into thte two distrinct groups. XOR numbers in each group, we can find a number in either group.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i< n ;i++){
            sum = sum ^ nums[i];
        }
        sum = sum & -sum ;// to get the last set bit
        vector<int> ans({0,0});
        for(int i = 0 ;  i< n ; i++){
            if((nums[i] & sum) == 0){
                ans[0]^=nums[i];
            }else{
                ans[1]^=nums[i];
            }
        }
        return ans;
    }
};
//TC : O(n)
//SC:O(1)

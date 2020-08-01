/*Problem Description : (LC 15)
---------------------------------------------------------------------
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
  
]

*/

//Code:
//------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()>=3){
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size()-2 ; i++){
            if(nums[i]<=0){ //there is use of checking if the first number is greater than zero, we will never find 3 number = 0
                if(i == 0 || i>0 && nums[i] != nums[i-1]){
                    int lo = i+1;
                    int hi= nums.size()-1;
                    int sum = 0 - nums[i];
                    while(lo<hi){
                    if(nums[lo] + nums[hi] == sum){
                        ans.push_back({nums[i], nums[lo], nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++; // to bypass duplicate
                        while(hi>lo && nums[hi] == nums[hi-1]) hi--; // to bypass duplicate
                        lo++;
                        hi--;
                    }else if(nums[lo] + nums[hi]<sum){
                        lo++;
                    }else{
                        hi--;
                    }
                }
                }
            }
        }
        }
        return ans;
        
    }
};

Problem Description:(LC 540)
---------------------------
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.
Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

Code:
--------------------------------------
class Solution {
public:
    int helper(vector<int>& nums, int l, int r){
        if(l>=r+1)
            return -1;
        int mid = l+(r-l)/2;
        cout<<mid<<"\n";
        if(mid == 0 && nums[mid] != nums[mid+1])
            return nums[mid];
        if(mid == nums.size()-1 && nums[mid] != nums[mid-1])
            return nums[mid];
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            return nums[mid];
        if(mid%2 == 0){
            if((mid-1)>=0 && nums[mid-1] == nums[mid]){
                return helper(nums, l,mid-1);
            }else{
                return helper(nums, mid+1, r);
            }
        }else{
            if((mid-1)>=0 && nums[mid-1] == nums[mid]){
                return helper(nums, mid+1, r);
            }else{
                return helper(nums, l, mid-1);
            }
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return helper(nums, 0, nums.size()-1);
        
    }
};

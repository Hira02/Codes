/*

Problem Description : (LC 368)
-------------------------------------------------------------------------
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
Code:
------------------------------------------------------------------------------
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
       sort(nums.begin(),nums.end());
        int n = nums.size();
        int count[n];
        int max_ = 0;
        int index  = -1;
        int indexing[n];
        for(int i = 0 ; i < n ; i++){
            count[i] = 1;
            indexing[i] = -1;
            for(int j = i-1 ; j>=0 ; j--){
                if(nums[j]%nums[i] == 0 || nums[i]%nums[j] == 0){
                if(1+count[j]>count[i]){
                    count[i] = count[j]+1;
                    indexing[i] = j;
                }
                   
                }
            }
             if(count[i]>max_){
                        max_ = count[i];
                        index = i;
                    }
        }
        while (index != -1){
            cout<<index<<" ";
        ans.push_back(nums[index]);
        index = indexing[index];
    }
        return ans;
    }
};

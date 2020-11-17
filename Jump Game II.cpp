/*
Problem Description : (LC 45)
------------------------------------------------------------------------------------------
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/

//Code:
//-------------------------------------------------------------------------------------
#1 : Dynamic Programming : TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return 0;
        int dp[n];
        dp[0] = 0;
        for(int i = 1 ; i <n ; i++){
            dp[i] = INT_MAX;
            for(int j = 0 ; j<i ; j++){
                if(nums[j]+j>=i)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[n-1];
    }
};

#2 : Greedy : accepted
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size<=1)
            return 0;
        int ladder = nums[0];
        int stairs = nums[0];
        int jumps = 1;
        for(int steps = 1 ; steps< size ; steps++){
            if(steps == size-1)return jumps;
            if(steps + nums[steps]>ladder)
                ladder = steps + nums[steps];
            stairs--;
            if(stairs == 0){
                jumps++;
                if(steps>= ladder)
                       return -1; //update made on 17-11-2020. Test case to follow [2,1,0,3]
                stairs = ladder - steps;
            }
            
        }
        return jumps;
    }
};
//Ref : https://www.youtube.com/watch?v=vBdo7wtwlXs&feature=emb_logo&ab_channel=IDeserve

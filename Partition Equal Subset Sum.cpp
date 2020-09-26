/*
Problem Description : (LC 416)
------------------------------------------------------------------------------------------------
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the
sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

Code:
-------------------------------------------------------------------------------------------------
class Solution {
public:
    bool helper(vector<int>& arr, int n, int sum){
    if(n == 0 && sum != 0)
    return false;
    if(sum == 0)
    return true;
    bool dp[sum+1][n+1];
    for(int i = 0 ; i <= n ; i++){
        dp[0][i] = true;
    }
    for(int i = 1 ; i <= sum ; i++){
        dp[i][0] = false;
    }
    for(int i = 1 ; i <= sum ;  i++){
        for(int j = 1 ; j <= n ; j++){
            dp[i][j] = dp[i][j-1];
            if(i>=arr[j-1]){
                dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
            }
        }
    }
    return dp[sum][n];
    }
    bool canPartition(vector<int>& arr) {
        if(arr.size() == 0)
            return true;
         int sum = 0;
	    for(int i = 0 ; i < arr.size() ; i++){
	        sum+=arr[i];
	    }
        if(sum%2 != 0)
	    return false;
        return helper(arr, arr.size(), sum/2);
    }
};
 
//TC : O(sum*n)
//SC : O(sum*n)

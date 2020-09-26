/*
Problem Description : (LC 216)
------------------------------------------------------------------------------
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
//Code:
//-------------------------------------------------------------------------------------------
class Solution {
public:

    void helper(int k, int n, vector<int>& tempStorage, vector<vector<int>>& result, int sum, int start){
       if(k == 0){
           if(sum == n){
               result.push_back(tempStorage);
           }else{
               return ;
           }
       }
        for(int i = start ; i<= 9 ; i++){
            sum += i;
            tempStorage.push_back(i);
            helper(k-1, n, tempStorage, result, sum, i+1);
            sum-=i;
            tempStorage.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tempStorage;
        vector<vector<int>> result;
        int sum = 0;
        helper(k, n, tempStorage, result, sum, 1);
        return result;
    }
};
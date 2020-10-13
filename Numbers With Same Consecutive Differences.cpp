/*
Problem Description : (LC 976)
------------------------------------------------------------------------------------------------
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example,
 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9
*/

//Code:
//----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void dfs(vector<int>& Ans, int n, int k, int num){
        if(n == 0){
            Ans.push_back(num);
            return;
        }else{
        int lastDig = num%10;
        if(lastDig + k <= 9)
            dfs(Ans, n-1, k, num*10 + lastDig+k);
        if(k!=0 && lastDig - k >=0)
            dfs(Ans, n-1, k, num*10 + lastDig - k);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1){
            return vector<int>{0,1,2,3,4,5,6,7,8,9};
        }
        vector<int> Ans;
        for(int i = 1 ; i <= 9 ; i++)
        dfs(Ans, N-1, K,i);
        return Ans;
    }
};
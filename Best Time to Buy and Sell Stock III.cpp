/*
Prolem Description : (LC 123) HARD
--------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

//Code: same code as if there are at most k transaction is allowed (LC 188)
//----------------------------------------------------------------------------------------------------------
#1:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<int> buy(3, INT_MIN), sell(3, 0);
        for(int i = 0 ; i < prices.size() ; i++){
            for(int t= 1 ; t<=2 ; t++){
                buy[t] = max(buy[t], sell[t-1]-prices[i]);
                sell[t] = max(sell[t], buy[t]+ prices[i]);
            }
        }
        return sell[2];
    }
};


#2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t_i10 = 0, t_i20 = 0;
        int t_i11 = INT_MIN, t_i21 = INT_MIN;
        for(int i = 0 ; i < prices.size() ; i++){
            t_i20 = max(t_i20 , t_i21 + prices[i]);
            t_i21 = max(t_i21 , t_i10 - prices[i]);
            t_i10 = max(t_i10 , t_i11 + prices[i]);
            t_i11 = max(t_i11 , -prices[i]);
        }
        return t_i20;
    }
};

mention : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

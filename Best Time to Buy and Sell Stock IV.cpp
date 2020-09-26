/*
Problem Description : (LC 188) HARD
--------------------------------------------------------------------------------------
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 */
//Solutions : 
/*
 https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/ 
 will not work for test cases with huge k value like ~ 1000000
 code link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/188630/C%2B%2B-8-lines-4-ms-DP
 Thanks for the optimised solution
 */

//Code:
//---------------------------------------------------------------------------------------------------------
class Solution {
public:
    int stockBuySell_II(vector<int>& prices, int n){
        int prevProfit = 0;
        int maxP = 0;
        for(int i = 1 ; i<n ; i++){
            int currP = max(prevProfit, prices[i] - prices[i-1]+ prevProfit);
            maxP = max(maxP, currP);
            prevProfit = currP;
        }
        return maxP;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        if(k>n/2){
            return stockBuySell_II(prices, n); // same as max profit buy and sell with any number of transaction
        }
        vector<int> buy(k+1, INT_MIN), sell(k+1, 0);
        for(int i = 0 ; i < n ; i++){
            for(int t = 1 ; t<= k ; t++){
                buy[t] = max(buy[t], sell[t-1]-prices[i]);
                sell[t] = max(sell[t] , buy[t]+prices[i]);
            }
        }
        return sell[k];
    }
};
//TC : O(n*k)
//SC : O(k+1)+O(k+1)



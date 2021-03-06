/*
Problem Description : (LC 309)
---------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times)
with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

Code:
--------------------------------------------------------------------------------------------
/*
There are two scenarios : 
case 1: having a stock
- if I am having a stock that means eithet I bought it today or I am carry forwarding it from last day
- var hold = max(hold, rest - prices[i])

case 2 :not having a stock
- if I am not having any stock today that means eithet I sold it today or not doing anything just carry forwarding

- var sold = max(rest, hold + prices[i])
*/

#1:
    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, hold = INT_MIN, rest = 0;
        for(int i = 0 ; i  <  prices.size() ; i++){
            hold = max(hold, rest - prices[i]);
            rest = max(sold, rest);
            sold = max(rest , hold+ prices[i]);
        }
        return max(rest, sold);
    }
};


#2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t_ik0 = 0, t_ik0pre = 0, t_ik1 = INT_MIN;
        for(int i = 0 ; i < prices.size() ; i++){
            int t_ik0old = t_ik0;
            t_ik0 = max(t_ik0, t_ik1 + prices[i]);
            t_ik1 = max(t_ik1, t_ik0pre - prices[i]);
            t_ik0pre = t_ik0old;
        }
        return t_ik0;
    }
};

mention : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

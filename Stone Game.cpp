Problem Description:(LC 877)
--------------------------
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row. 
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
Example 1:

Input: [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.


Solution Description:  
-------------------------------------------

     //if alex takes first pile, then in the next chance alex has two options either take second pile from begining(is Lee takes
     // first pile from end) or last pile(if Lee takes second pile from begining)
    // if alex takes last pile, then in the next chance alex has two options either take second pile from begining(if Lee takes first pile)
    // or third last pile(if Lee takes second last pile)

Code:
------------------------------------------
class Solution {
public:
    int dp[1005][1005];
    int fun(int l, int r, vector<int> &piles){
        if(l == r-1)
            return max(piles[l], piles[r]);
     if(dp[l][r] !=-1) return dp[l][r];   
        int left = piles[l] + max(fun(l+2, r, piles), fun(l+1, r-1, piles));
        int right = piles[r] + max(fun(l+1, r-1, piles), fun(l, r-2, piles));
       return dp[l][r] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int r = piles.size();
        int alex = fun(0, r-1, piles);
        int sum = 0;
        for(int  i = 0 ; i < r ; i++) sum+=piles[i];
        return alex>(sum-alex);
        
    }
};

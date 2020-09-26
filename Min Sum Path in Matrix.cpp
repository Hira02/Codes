/*
Problem Description : https://www.interviewbit.com/problems/min-sum-path-in-matrix/
-------------------------------------------------------------------------------------------------------
Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum 
of all numbers along its path.

NOTE: You can only move either down or right at any point in time.



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).



Example Input
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]


Example Output
Output 1:

 9


Example Explanation
Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8
 */
//Code:
//------------------------------------------------------------------------------------------------
int Solution::minPathSum(vector<vector<int> > &cost) {
    int row = cost.size();
    int col = cost[0].size();
    
    for (int i=1 ; i<row ; i++){ 
        cost[i][0] += cost[i-1][0]; 
    } 
    for (int j=1 ; j<col ; j++){ 
        cost[0][j] += cost[0][j-1]; 
    } 
    for (int i=1 ; i<row ; i++) { 
        for (int j=1 ; j<col ; j++) { 
            cost[i][j] +=  min(cost[i-1][j], cost[i][j-1]); 
        } 
    } 
    return cost[row-1][col-1]; 
}

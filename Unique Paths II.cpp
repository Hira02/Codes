/*
Problem Description : (LC 63)
-------------------------------------------------------------------
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid
(marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?


https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

Code:
----------------------------------------------------------------------------------------------------
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        // filling the first row
        for(int i = 1 ; i < c ; i++){
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1)?1:0;
        }
        // filling the first column
        for(int j = 1 ; j<r ; j++){
            obstacleGrid[j][0]  = (obstacleGrid[j][0] == 0 && obstacleGrid[j-1][0] == 1)?1:0;
        }
        for(int i = 1; i<r ; i++){
            for(int  j = 1 ; j < c ; j++){
                if(obstacleGrid[i][j] == 0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }else{
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[r-1][c-1];
        
    }
};

/*
Problem Description : (LC 1293) HARD
----------------------------------------------------------------------------------------------------------------------
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell
 in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

 

Example 1:
https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:
https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

*/
//Code:
//-----------------------------------------------------------------------------------------------------------------------------------------------
int X[] = {0, -1, 0, 1};
int Y[] = {1, 0, -1, 0};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        // if(grid[rows-1][cols-1] == 1){
        //     grid[rows-1][cols-1] = 0;
        //     k--;
        //     if(k<0)
        //         return -1;
        // }
        queue<vector<int>> q;
        int visited[rows][cols][k+1];
        memset(visited, 0, sizeof(visited));
        visited[0][0][0]  = 1;
        q.push({0,0,0});
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                 auto t= q.front();
                // cout<<t<<"\n";
                 q.pop();
                int r = t[0]; int c = t[1] ; int currK = t[2];
                // cout<<r<<" "<<c<<" "<<currK<<"\n";
               
                if(r == rows-1 && c == cols-1)
                    return res;
                for(int j = 0; j <4 ; j++){
                    int nextR = X[j] + r;
                    int nextC = Y[j] + c;
                    int nextK = currK;
                    if(nextR>=0 && nextC>=0 && nextR<rows && nextC<cols){
                        if(grid[nextR][nextC] == 1){
                            nextK++;
                        }
                        if(nextK<=k && visited[nextR][nextC][nextK] == 0){
                            visited[nextR][nextC][nextK] = 1;
                            q.push({nextR, nextC, nextK});
                        }
                    }
                }
                
             }
            res++;
            }
        return -1;
           
    }
};
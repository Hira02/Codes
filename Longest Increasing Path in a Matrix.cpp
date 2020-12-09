/*
Problem Description : (LC 329) HARD
-------------------------------------------------------------------------------------------------------------------------
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or 
move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
//Code:
//--------------------------------------------------------------------------------------------------------------------
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& cache){
        if(cache[i][j] != 0)
            return cache[i][j];
        int max_  = 1;
        
        for(int k = 0 ; k < 4 ; k++){
            int x = X[k] + i;
            int y = Y[k] + j;
            // cout<<x<<" "<<y<<"\n";
            if(x<0 || y<0 || x>= n || y>=m || matrix[x][y]<=matrix[i][j])
                continue;
            int val = 1+dfs(matrix, x, y, n, m, cache);
            max_ = max(max_, val);
        }
        cache[i][j] = max_;
        return max_;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>>cache(n, vector<int>(m, 0));
        int lip =0;
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
                int val = dfs(matrix, i, j, n, m, cache);
                lip = max(lip, val);
            }
        }
        return lip;
    }
    
};
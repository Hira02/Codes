/*
Problem Description: :(LC 980)
--------------------------------------------------------------------------------------------
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20
*/
//Code:
//-------------------------------------------------------------------------------------------------
  int X[] = {-1,0,1, 0};
    int Y[] = {0,-1,0,1};
class Solution {
public:
  
    void backtrack(vector<vector<int>>& grid, int row, int col , int* totalPath, int goodCell){
        if(grid[row][col] == 2 && goodCell == 1){
            (*totalPath)++;
            return ;
        }
        int temp = grid[row][col];
        grid[row][col] = -2;//making as visited
        goodCell--;
        for(int k =  0;  k <4 ; k++){
            int x = X[k]+row;
            int y = Y[k]+col;
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]>=0){
               backtrack(grid, x, y, totalPath, goodCell) ;
            }
        }
        grid[row][col] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
          int goodCell = 0;
        int start_row = 0;
        int start_col = 0;
        int totalPath = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] >= 0){
                    goodCell++;
                }
                if(grid[i][j] == 1){
                    start_row = i;
                    start_col = j;
                }
                
            }
        }
        
        backtrack(grid, start_row, start_col, &totalPath, goodCell);
        return totalPath;
    }
};
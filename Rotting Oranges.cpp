/*
Problem Description : (LC 994)
-------------------------------------------------------------------------------------
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

https://assets.leetcode.com/uploads/2019/02/16/oranges.png

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
//Code:
//---------------------------------------------------------------------------------------------------------------
int X[] = {-1, 0, 1, 0};
int Y[] = {0, -1, 0, 1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int totalMin= 0;
        int row = grid.size();
        int col = grid[0].size() ; 
        int count1 =0 ;
        queue<pair<int, int>> q;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j <col; j++){
                if(grid[i][j] == 2){
                   q.push(make_pair(i,j));
                }else if(grid[i][j] == 1){
                    count1++;
                }
            }
           
        }
        if(count1 == 0)
            return 0;
        while(!q.empty()){
            int size = q.size();
            totalMin++;
            for(int p = 0; p<size ; p++){
                pair<int, int> top = q.front();
                int i = top.first;
                int j = top.second;
                q.pop();
                for(int k = 0 ; k < 4;  k++){
                    int x = X[k] + i;
                    int y = Y[k] + j;
                    if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0 || grid[x][y] == 2) continue;
                        grid[x][y] = 2;
                        count1--;
                        q.push(make_pair(x, y));
                }
            }
        }
         return (count1 == 0)? totalMin-1: -1;
    }
};


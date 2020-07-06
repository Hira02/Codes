/*
Problem Description : (LC 289)
--------------------------------------------------------------------------
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules
(taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules
simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their 
updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches 
the border of the array. How would you address these problems?
*/

Code:
---------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int d[8][2] = {{-1,0},{0,-1},{-1,-1},{0,1},{-1,1},{1,1},{1,0},{1,-1}};
        int row = board.size();
        int col = board[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j  < col ; j++){
                int live = 0;
                for(int k = 0 ; k < 8 ; k++){
                    int x = d[k][0] + i;
                    int y = d[k][1] + j;
                    if(x<0 || x>=row || y<0 || y>=col)
                        continue;
                    if(board[x][y] &1)
                        live++;
                }
                if(board[i][j] == 0){
                    if(live == 3){
                        board[i][j] = 2;
                    }
                }else{
                    if(live<2 || live>3){
                        board[i][j] = 1;
                    }else{
                        board[i][j] = 3;
                    }
                }
            }
        }
       for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j  < col ; j++){
                board[i][j]>>=1;
            }
       }
        
    }
};

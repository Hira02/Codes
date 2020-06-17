/*
Problem Description : (LC 130)
--------------------------------------------------------
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

Approach : 
----------------------------------------------------------------------------------------------
First, check the four border of the matrix. If there is a element is
'O', alter it and all its neighbor 'O' elements to '1'.

Then ,alter all the 'O' to 'X'

At last,alter all the '1' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X


Code:
------------------------------------------------------------------------------------------------
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j , int row, int col){
        if(i<0 || i>row-1  || j<0 || j>col-1)
            return ;
        if(board[i][j] == 'O')
            board[i][j] = '*';
        if(i>0 && board[i-1][j] == 'O')
            dfs(board, i-1,j, row, col);
        if(i<row-1 && board[i+1][j] == 'O')
            dfs(board, i+1,j, row, col);
        if(j>0 && board[i][j-1] == 'O')
            dfs(board, i,j-1, row, col);
        if(j<col-1 && board[i][j+1] == 'O')
            dfs(board, i,j+1, row, col);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()<=0)
            return ;
        int row = board.size();
        int col = board[0].size();
        if(row <=0 || col<=0)
            return ;
        for(int i = 0 ; i < row ; i++){
           if(board[i][0]=='O') dfs(board, i, 0, row, col);
            
            if(board[i][col-1] == 'O') dfs(board, i, col-1, row, col);
            
        }
        for(int j = 0 ; j < col ; j++){
           if(board[0][j] == 'O') dfs(board, 0, j, row, col);
            if(board[row-1][j] == 'O'){
                dfs(board, row-1, j, row, col);
            }
        }
        for(int i  = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
               else if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
        
    }
};

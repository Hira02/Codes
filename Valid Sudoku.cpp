/*
Problem Description : (LC 36)
-------------------------------------------------------------------------------------
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

Code:
-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
//     bool rowValidation(vector<vector<char>>& board, int row){
//         set<char> Set;
//         for(int i = 0 ; i < 9 ; i++){
//             char value = board[i][row];
//             if(Set.find(value) != Set.end())
//                 return false;
//             else if(value != '.')
//                 Set.insert(value);
//         }
//         return true;
//     }
//      bool colValidation(vector<vector<char>>& board, int col){
//         set<char> Set;
//         for(int i = 0 ; i < 9 ; i++){
//             char value = board[col][i];
//             if(Set.find(value) != Set.end())
//                 return false;
//             else if(value != '.')
//                 Set.insert(value);
//         }
//         return true;
//     }
//      bool boxValidation(vector<vector<char>>& board, int row, int col){
//         set<char> Set;
//          cout<<row<<" "<<col<<" "<<"\n";
//         for(int i = 0 ; i < 3 ; i++){
//             for(int j = 0 ; j < 3 ; j++){
//                  char value = board[i + row][j + col];
//                  if(Set.find(value) != Set.end())
//                     return false;
//                  else if(value != '.')
//                      Set.insert(value);
//             }
           
           
//         }
//         return true;
//     }
//     bool isValid(vector<vector<char>>& board, int row, int col){
//         return rowValidation(board, row) && colValidation(board, col) && boxValidation(board, row - row%3, col - col%3);
//     }
//@https://leetcode.com/problems/valid-sudoku/discuss/15464/My-short-solution-by-C%2B%2B.-O(n2) for his awesome sol
    bool isValidSudoku(vector<vector<char>>& board) {
        int board1[9][9] = {0}, board2[9][9] = {0}, board3[9][9] = {0};
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(board[i][j] != '.'){
               int num = board[i][j] - '0'- 1;
                int k = (i/3)*3+j/3;
                if(board1[i][num] || board2[j][num] || board3[k][num])
                    return false;
                board1[i][num] = 1;
                board2[j][num] = 1;
                board3[k][num] = 1;
            }
            }
        }
        return true;
    }
};

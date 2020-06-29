/*

Problem Description : (LC 79)
------------------------------------------------------------------------------------
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
Code:
-----------------------------------------------------------------------------------
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i ,int j, string word, int index){
        if(index == word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size())
            return false;
        if(board[i][j] != word[index])
            return false;
        char temp = board[i][j];
        board[i][j] = ' '; // temporary updation of the current block to stop relooking of same block
        if(dfs(board, i+1, j, word, index+1) || dfs(board, i-1, j, word, index+1) ||
          dfs(board, i, j+1, word, index+1) || dfs(board, i, j-1, word, index+1))
            return true;
        board[i][j] = temp; // making it as previous becuase if we didn't find then for next iteration this block should contain original value
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();
        for(int i = 0 ; i < rows;  i++){
            for(int j = 0 ; j < columns ; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};

//TC : O(n) : if n is the total number of words in the grid. As we are going through each value
// SC : O(n), in worst case we may have to store each word in the grid

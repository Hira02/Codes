/*
Problem Description : (LC 48)
------------------------------------------------------------------------------
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix
and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
  */
  
  CodE:
  -----------------------------------------------------------------------------------
  
  class Solution {
public:
    // void swap(int* a, int* b){
    //     int temp = *a;
    //     *a = *b;
    //     *b = temp;
    // }
    // void transpose(vector<vector<int>>& mat){
    //     for(int i = 0 ; i < mat.size() ; i++){
    //         for(int j = i ; j < mat[i].size() ; j++){
    //             swap(&mat[i][j], &mat[j][i]);
    //         }
    //     }
    // }
    // void reverseCols(vector<vector<int>>& mat){
    //     int row = mat.size();
    //     int col = mat[0].size();
    //     for(int i = 0 ; i < row ; i++){
    //         for(int j = 0 ; j < col/2 ; j++){
    //             swap(&mat[i][j], &mat[i][col - j - 1]);
    //         }
    //     }
    // }
    void rotate(vector<vector<int>>& matrix) {
        // transpose(matrix);
        // reverseCols(matrix);
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0 ; i < row/2 ; i++){//number of cycle
            for(int j = i ; j< row  -i -1 ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row - j - 1][i];
                matrix[row - j - 1][i] = matrix[row - i - 1][row - j - 1];
                matrix[row - i - 1][row - j - 1] = matrix[j][row - i - 1];
                matrix[j][row - i - 1] = temp;
            }
        }
        
    }
};
// commented process will also work

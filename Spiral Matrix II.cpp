/*
Problem Description : (LC 59)
------------------------------------------------------------------------------
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
//Code:
//-------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if(n == 0)
            return matrix;
        int rowStart = 0;
        int rowEnd = n;
        int colStart = 0;
        int colEnd = n;
        int num = 1;
        while(rowStart<rowEnd && colStart < colEnd){
            for(int i = colStart ; i<colEnd ; i++){
                matrix[rowStart][i] = num++;
            }
            rowStart++;
            for(int i = rowStart ; i<rowEnd ; i++){
                matrix[i][colEnd -1 ] = num++;
            }
            colEnd--;
            if(rowStart<rowEnd){
            for(int i = colEnd-1 ; i>=colStart ; i--){
                matrix[rowEnd-1][i] = num++;
            }
            rowEnd--;
            }
            if(colStart<colEnd){
            for(int i = rowEnd-1  ; i>=rowStart ; i--){
                matrix[i][colStart]  = num++;
            }
            colStart++;
            }
        }
        return matrix;
    }
};
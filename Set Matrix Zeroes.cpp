/*
Problem Description  :(LC 73)
---------------------------------------------------
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
Code:
------------------------------------------------------------------------
class Solution {
public:
    int abc = 99999;
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(matrix[i][j] == 0)
                    matrix[i][j] = abc;
            }
        }
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == abc){
                    int k=0;
                    while(k<m){
                        if(matrix[k][j] == abc)
                            k++;
                        else
                            matrix[k++][j] = 0;
                            
                    }
                    k=0;
                    while(k<n){
                        if(matrix[i][k] == abc)
                            k++;
                        else
                            matrix[i][k++] = 0;
                    }
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

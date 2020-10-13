/*
Problem Description : (LC 54)
-------------------------------------------------------------------------------------------------
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
//Code:
//-----------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int r1 = 0;
        int r2 =  matrix.size();
        int c1 = 0;
        int c2 = matrix[0].size();
        while(r1<r2 && c1<c2){
            for(int c = c1 ; c<c2 ; c++){
                ans.push_back(matrix[r1][c]);
            }
            // c1++;
            r1++;
            for(int r = r1 ; r<r2 ; r++){
                ans.push_back(matrix[r][c2-1]);
            }
            c2--;
            if(r1<r2){
                for(int c =c2-1 ; c>=c1 ; c--){
                    ans.push_back(matrix[r2-1][c]);
                }
                r2--;
            }
           if(c1<c2){
               for(int r = r2-1 ; r>=r1 ; r--){
                   ans.push_back(matrix[r][c1]);
               }
               c1++;
           }
            // c1++;
            // r1++;
        }
        return ans;
    }
};
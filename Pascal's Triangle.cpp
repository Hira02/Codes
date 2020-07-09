/*
Problem Description : (LC 181)
----------------------------------------------------------------------
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.
https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

Code:
------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> rows;
        if(numRows == 0)
            return triangle;
        rows.push_back(1);
        triangle.push_back(rows);
        for(int i = 1 ; i < numRows ; i++){
            vector<int> rows;
            vector<int> prevRow = triangle[i-1];
            rows.push_back(1);
            for(int j = 1; j < i ; j++){
                rows.push_back(prevRow[j-1] + prevRow[j]);
            }
            rows.push_back(1);
            triangle.push_back(rows);
        }
        return triangle;
    }
};

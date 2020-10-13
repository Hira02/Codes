/*
Problem Description: ( LC 240)
----------------------------------------------------------------------------------------------------------
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
//Code:
//---------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();

        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
// Approach : https://assets.leetcode.com/static_assets/discuss/uploads/files/1488858512318-monosnap-2017-03-06-22-48-17.jpg
//TC : O(row + col)
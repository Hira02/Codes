/*
problem Description : (LC 120)
--------------------------------------------------------------------------------------------------
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
//Code:
//-------------------------------------------------------------------------------------------------
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> copyOfLastRow = triangle[triangle.size()-1];
        for(int rows = triangle.size()-2 ; rows>=0 ; rows--){
            for(int currBranch = 0 ; currBranch<= rows ; currBranch++){
                copyOfLastRow[currBranch] = min(copyOfLastRow[currBranch], copyOfLastRow[currBranch+1]) + triangle[rows][currBranch];
            }
        }
        return copyOfLastRow[0];
    }
};
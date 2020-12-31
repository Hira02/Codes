/*
Problem Description : (LC 498)
---------------------------------------------------------------------------------------------------------
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 https://assets.leetcode.com/uploads/2018/10/12/diagonal_traverse.png

Note:

The total number of elements of the given matrix will not exceed 10,000.
*/
//Code:
//---------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if ( m == 0 ) return {};
        int n = matrix[0].size();
        
        vector<int> ret;
        for( int k=0; k<=m+n-2; k++ )
        {
            int start, end, dir;
            if ( k % 2 == 0 )
            {
                start = k, end = -1, dir = -1;;
            }
            else
            {
                start = 0, end = k+1, dir = 1;
            }
            for( int i=start; i!=end; i += dir )
            {
                int j = k - i;
                if ( i>=0 && i<m && j>=0 && j<n )
                    ret.push_back( matrix[i][j] );
            }
        }
        return ret;
    }
};
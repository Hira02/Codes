/*
Problem Description : (LC 1007)
------------------------------------------------------------------------------------------------------------
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino. 
 (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:
https://assets.leetcode.com/uploads/2019/03/08/domino.png

Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6
*/
//Code:
//--------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int f(int target, vector<int> &A, vector<int> &B)
    {
        int swapCount = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != target)
            {
                if (B[i] != target)
                {
                    return INT_MAX;
                }
                else
                {
                    swapCount++;
                }
            }
        }
        return swapCount;
    }
    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int val = min({f(A[0], A, B), f(B[0], A, B), f(A[0], B, A), f(B[0], B, A)});
        return val == INT_MAX ? -1 : val;
    }
};
//Sol : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252802/Thinking-Process
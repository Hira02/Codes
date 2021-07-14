/*
Problem Description : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/?company[]=Amazon&company[]=Amazon&difficulty[]=0&difficulty[]=1&difficulty[]=2&page=1&query=company[]Amazondifficulty[]0difficulty[]1difficulty[]2page1company[]Amazon#

Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9 
2 5 8 
1 4 7
Your Task:
You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function. 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 50
1 <= matrix[][] <= 100
*/
//Code:
//-------------------------------------------------------------------------------------------------------------------------------------------
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i = 0 ; i < (row+1)/2 ; i++){
        for(int j = i ; j<col-i-1 ; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][col-1-i];
            matrix[j][col-1-i] = matrix[col-1-i][row-1-j];
            matrix[col-1-i][row-1-j] = matrix[col-1-j][i];
            matrix[col-1-j][i] = temp;
            // print(matrix);
        }
    }
}

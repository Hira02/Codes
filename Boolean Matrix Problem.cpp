/*
Problem Description : https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0
--------------------------------------------------------------------------------------------------
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all
 the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0

Explanation:
Testcase1: Since only first element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.
*/
//Code:
//-----------------------------------------------------------------------------------------------------------------------------\
#include <bits/stdc++.h>
using namespace std;
void convert( vector<vector<int>>& mat, int n, int m){
    int first_row = false;
    int first_col = false;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j  < m  ;  j++){
            if(i == 0 && mat[i][j] == 1)
            first_row = true;
            if(j == 0 && mat[i][j] == 1)
            first_col = true;
            if(mat[i][j] == 1)
            {
                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }
    for(int i= 1 ; i < n  ; i ++){
        for(int j = 1 ; j  < m ; j++){
            if(mat[i][0] == 1 || mat[0][j] == 1){
                mat[i][j] = 1;
            }
           
        }
    }
    
    if(first_row == true){
        for(int i = 0 ; i < m ; i++){
            mat[0][i] = 1;
        }
    }
    if(first_col == true){
        for(int i = 0 ; i < n ; i++){
            mat[i][0] = 1;
        }
    }
}
int main() {
	int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
         vector<vector<int>> mat;
        // vector<vector<bool>> visited;
        for(int i = 0 ; i < n ; i++){
            vector<int> row;
            // vector<bool> visRow;
            for(int j = 0 ; j < m ; j++){
                int val;
                cin>> val;
                row.push_back(val);
                // visRow.push_back(false);
            }
            mat.push_back(row);
            // visited.push_back(visRow);
        }
        convert(mat, n, m);
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        cout<<"\n";
}
	return 0;
}
 
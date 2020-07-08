/*
Problem Description  : (interviewbit)
----------------------------------------------------------------------------
Given a binary matrix A of size N x M.

Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.

.



Problem Constraints
1 <= N, M <= 102

A[i][j]=0 or A[i][j]=1



Input Format
First argument is a 2D binary matrix Aof size  N x M.



Output Format
Return a single interger denoting the length of largest region.



Example Input
Input 1:

 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
Input 2:

 A = [  [1, 1, 1]
        [0, 0, 1]
    ]


Example Output
Output 1:

 6
Output 2:

 4


Example Explanation
Explanation 1:

 The largest region is denoted by red color in the matrix:
    00110
    10110
    01000
    00001
Explanation 2:

 The largest region is:
    111
    001

*/

Code:
-------------------------------------------------------------------------------------------------------
int check(vector<vector<int> > &A, int i, int j ,vector<vector<bool>>& visited){
    if(visited[i][j] == true)
    return 0;
    visited[i][j] =  true;
    int count= 0 ;
    if(i>0 && A[i-1][j] == 1 && visited[i-1][j] == false){
        count = count + 1 + check(A, i-1, j, visited);
    }
    if(i<A.size()-1 && A[i+1][j] == 1 && visited[i+1][j] == false){
         count = count + 1 + check(A, i+1, j, visited);
    }
    if(j>0 && A[i][j-1] == 1 && visited[i][j-1] == false){
         count = count + 1 + check(A, i, j-1, visited);
    }
    if(j<A[i].size()-1 && A[i][j+1] == 1 && visited[i][j+1] == false){
         count = count + 1 + check(A, i, j+1, visited);
    }
    if(i>0 && j>0 && A[i-1][j-1] == 1 && visited[i-1][j-1] == false){
         count = count + 1 + check(A, i-1, j-1, visited);
    }
    if(i<A.size()-1 && j<A[i].size()-1 && A[i+1][j+1] == 1 && visited[i+1][j+1] == false){
         count = count + 1 + check(A, i+1, j+1, visited);
    }
    if(i<A.size()-1 && j>0 && A[i+1][j-1] == 1 && visited[i+1][j-1] == false){
         count = count + 1 + check(A, i+1, j-1, visited);
    }
    if(i>0 && j<A[i].size()-1 && A[i-1][j+1]==1 && visited[i-1][j+1] == false){
         count = count + 1 + check(A, i-1, j+1, visited);
    }
    return count;
}
int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    int n = A.size();
    int m = A[0].size();
    vector visited(n,vector<bool>(m,false));
    for(int i = 0 ; i  < n ; i++){
        for(int j = 0 ;  j < m  ; j++){
            if(A[i][j] == 1){
                int count = 1+check(A, i, j, visited);
            if(count>ans)
            ans = count;
            }
        }
    }
    return ans;
}

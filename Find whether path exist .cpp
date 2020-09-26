/*
Problem Description : https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
-----------------------------------------------------------------------------------------------------
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

 

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. 
Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of 
the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.
*/
//Code:
//--------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int X[] = {-1,0, 1, 0};
int Y[] = {0, -1, 0, 1};
vector<int> findSource(vector<vector<int>>& mat, int n){
    for(int i = 0 ;i<n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(mat[i][j] == 1)
            return{i,j};
        }
    }
}
int canGo(vector<vector<int>>& mat, int n, int sI, int sJ, int i, int j, vector<vector<bool>>& vis){
    if(mat[i][j] == 2)
    return 1;
    if(vis[i][j] == true)
    return false;
    vis[i][j] = true;
    for(int k = 0 ; k< 4 ; k++){
        int x = X[k]+i;
        int y = Y[k]+j;
        if(x>=0 && y>= 0&& x<n && y<n && vis[x][y] == false && (mat[x][y] == 3 || mat[x][y] == 2))
        if(canGo(mat, n, sI, sJ, x, y, vis))
        return true;
    }
    return false;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> mat;
	    mat.resize(n,vector<int>(n));
	    vector<vector<bool>> vis;
	    vis.resize(n,vector<bool>(n, false));
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j ++){
	            cin>>mat[i][j];
	        }
	    }
	    vector<int> Source = findSource(mat, n);
	    
	    cout<<canGo(mat, n, Source[0], Source[1], Source[0], Source[1], vis)<<"\n";
	    
	}
	return 0;
}
 
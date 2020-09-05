/*
Problem Description : https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
-------------------------------------------------------------------------------------------------------------------
Given a Matrix containing 0s and 1s. Find the unit area of the largest region of 1s (refer Your Task for complete details).

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of 
each testcase contains 2 space separated integers N and M. Then in the next line are the nxm inputs of 
the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findArea() which
 takes the number of rows N, the number of columns M and the matrix A, as inputs and returns the unit 
 area of the largest region of connected 1s.
Each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two filled 
cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.
 If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M).

Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[ ][ ] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with a total 4 1s (colored in Red).
Testcase 2: Matrix can be shown as follows:
1 1 1
Largest region of 1s in the above matrix is with a total of 3 1s (colored in Red).
*/
//Code:
//-----------------------------------------------------------------------------------------------------------
int X[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int Y[] = {0, -1, -1, -1, 0, 1, 1, 1};
int searchForArea(int A[SIZE][SIZE], int i, int j, int n, int m , vector<vector<bool>>& vis, int* currCount){
   
    vis[i][j] = true;
    (*currCount)+=1;
    for(int k = 0 ; k < 8 ; k++){
        int x = X[k]+i;
        int y = Y[k]+j;
        if(x>=0 && y>=0 && x<n && y<m && vis[x][y] == false && A[x][y] == 1){
             
         searchForArea(A, x, y, n, m, vis, currCount);
        }
    }
    return *currCount;
    
    
}
int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    // Your code here
    vector<vector<bool>> vis;
    vis.resize(N, vector<bool>(M, false));
    int maxArea = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ;j++){
            int currCount = 0;
            if(vis[i][j] == false && A[i][j] == 1){
                maxArea = max(maxArea , searchForArea(A, i, j, N, M, vis,&currCount ));
            }
        }
    }
    return maxArea;
}
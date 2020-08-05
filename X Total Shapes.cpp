/*
Problem description : GFG
-------------------------------------------------------------------------------
Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's
 (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines.
 The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements
  in the array.

Output:
For each testcase, print number of shapes.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M) (recursive). 

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). 
So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.

 */

#include<bits/stdc++.h>
using namespace std;
int r[] = {-1, 0, 1, 0};
int c[] = {0, 1, 0, -1};
void dfs(vector<vector<bool>>& vis, int n, int m, int i, int j, vector<vector<char>>& v){
    if( vis[i][j] || v[i][j] != 'X')
    return;
    
    else {
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int x  = i+r[k];
            int y = j+c[k];
            if( x>=0 && x<n && y>=0 && y<m &&  v[x][y] == 'X' && vis[x][y]==false)
              dfs(vis, n, m,x , y, v);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
         vector<vector<char>> mat;
        vector<vector<bool>> visited;
        for(int i = 0 ; i < n ; i++){
            vector<char> row;
            vector<bool> visRow;
            for(int j = 0 ; j < m ; j++){
                char val;
                cin>> val;
                row.push_back(val);
                visRow.push_back(false);
            }
            mat.push_back(row);
            visited.push_back(visRow);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(visited[i][j] == false && mat[i][j] == 'X'){
                   dfs(visited, n, m, i, j, mat);
                    count++;
                }
            }
        }
        // conflict check
        cout<<count<<"\n";
    }

}
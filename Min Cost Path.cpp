/*
Problem Description : InterviewBit
-----------------------------------------------------------------------------------
You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times.
 
 */
 
 Code:
 ----------------------------------------------------------------------------------------------------------------------------------
 #define P pair<int,int>
#define F first
#define S second

int Solution::solve(int n, int m, vector<string> &grid) {
    vector< vector<bool> > vis(n , vector<bool>(m,0));
    priority_queue<pair < int , P > , vector< pair < int , P > > , greater < pair < int , P > > > q;    
    q.push({0,{0,0}});
    int ans = 0;
    while(!q.empty()){
        int changes = q.top().F;
        int i = q.top().S.F;
        int j = q.top().S.S;
        q.pop();
        if(vis[i][j] == true){
            continue;
        }
        if(i == n-1 && j == m-1){
            ans = changes;
        }
        if(i-1 >= 0 && !vis[i-1][j]){
            q.push({changes + ((grid[i][j] == 'U') ?0 :1) ,{i-1,j}});
        }
        if(j-1 >= 0 && !vis[i][j-1]){
            q.push({changes + ((grid[i][j] == 'L') ?0 :1) ,{i,j-1}});
        }
        if(i+1 < n && !vis[i+1][j]){
            q.push({changes + ((grid[i][j] == 'D') ?0 :1) ,{i+1,j}});
        }
        if(j+1 < m && !vis[i][j+1]){
            q.push({changes + ((grid[i][j] == 'R') ?0 :1) ,{i,j+1}});
        }
        vis[i][j] = true;        
    }    
    return ans;
}

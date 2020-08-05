//https://www.interviewbit.com/problems/valid-path/
/*
Problem Description : 
There is a m*n rectangular matrix whose top-left(start) location is (1, 1) and bottom-right(end) location is (m*n). There are k circles each with radius r.
Find if there is any path from start to end without touching any circle.

The input contains values of m, n, k, r and two array of integers X and Y, each of length k. (X[i], Y[i]) is the centre of ith circle.
Input1 : m = 5, n = 5, k = 2, r = 1, 
         X = {1, 3}, Y = {3, 3}
Output1 : Possible
https://media.geeksforgeeks.org/wp-content/uploads/example-1-1-300x293.png
Here is a path from start to end point.

Input2 : m = 5, n = 5, k = 2, r = 1, 
         X = {1, 1}, Y = {2, 3}.
Output2 : Not Possible
https://media.geeksforgeeks.org/wp-content/uploads/example-2-1-300x292.png

*/

/*

Approach : Check if the centre of a cell (i, j) of the rectangle comes within any of the circles then do not traverse through that cell and mark that as ‘blocked’.
Mark rest of the cells initially as ‘unvisited’. Then use BFS to find out shortest path of each cell from starting position. 
If the end cell is visited then we will return “Possible” otherwise “Not Possible”.

Algorithm :

Take an array of size m*n. Initialize all the cells to 0.
For each cell of the rectangle check whether it comes within any circle or not (by calculating the distance of that cell from each circle). 
If it comes within any circle then change the value of that cell to -1(‘blocked’).
Now, apply BFS from the starting cell and if a cell can be reached then change the value of that cell to 1.
If the value of the ending cell is 1, then return ‘Possible’, otherwise return ‘Not Possible’.

Source:  https://www.geeksforgeeks.org/path-rectangle-containing-circles/
*/
Code:
--------------------------------------------------------
int X[] = {-1,-1,-1,0,1,1,1,0};
int Y[] = {-1,0,1,1,-1,0,-1,-1};
 
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    int rect[A+1][B+1];
    memset(rect, 0 , sizeof(rect));
 
    for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
            for(int k=0;k<C;k++)
                if(sqrt(pow(E[k]-i, 2) + pow(F[k]-j, 2)) <= D)
                {
                    rect[i][j] = 1;
                    break;
                }
 
    if(rect[0][0]==1 || rect[A][B]==1)
        return "NO";
 
    queue<pair<int,int> > q;
    q.push({0,0});
    rect[0][0] = 1;
 
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if(x==A && y==B)
            return "YES";
 
        for(int i=0;i<8;i++)
        {
            int newx = x + X[i];
            int newy = y + Y[i];
            if(newx>=0 && newx<=A && newy>=0 && newy<=B && rect[newx][newy]==0)
            {
                rect[newx][newy] = 1;
                q.push({newx,newy});
            }
        }
    }
    return "NO";
}

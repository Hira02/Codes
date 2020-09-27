/*
Problem Description : https://www.interviewbit.com/problems/knight-on-chess-board/
----------------------------------------------------------------------------------------------------------------
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move 
to the destination or not.

https://i.imgur.com/lmKL4AU.jpg

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:

1 <= A, B <= 500
Example

Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
Output 1:
    6

Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.

    */
//Code:
//-----------------------------------------------------------------------------------------------------------------
class Cell{
  public:
    int x;
    int y;
    int dis;
    Cell(int a, int b ,int d){
        x = a;
        y = b;
        dis = d;
    }
    
};
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
    queue<Cell>q;
    vector<vector<int>> visited(A+1, vector<int>(B+1, 0));
    q.push(Cell(C,D,0));
    visited[C][D] = 1;
    while(!q.empty()){
        Cell t = q.front();
        q.pop();
        // cout<<t.x<<" "<<t.y<<"\n";
        if(t.x == E && t.y == F){
            return t.dis;
        }
        for(int i = 0 ; i < 8 ; i++){
            int x = t.x+dx[i];
            int y = t.y+dy[i];
            if(x>0 && y>0 && x<=A && y <= B && visited[x][y] == 0){
                visited[x][y] = 1;
                q.push(Cell(x,y,t.dis+1));
            }
        }
        
    }
    return -1;
}

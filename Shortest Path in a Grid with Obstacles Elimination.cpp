
int X[] = {0, -1, 0, 1};
int Y[] = {1, 0, -1, 0};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        // if(grid[rows-1][cols-1] == 1){
        //     grid[rows-1][cols-1] = 0;
        //     k--;
        //     if(k<0)
        //         return -1;
        // }
        queue<vector<int>> q;
        int visited[rows][cols][k+1];
        memset(visited, 0, sizeof(visited));
        visited[0][0][0]  = 1;
        q.push({0,0,0});
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                 auto t= q.front();
                // cout<<t<<"\n";
                 q.pop();
                int r = t[0]; int c = t[1] ; int currK = t[2];
                // cout<<r<<" "<<c<<" "<<currK<<"\n";
               
                if(r == rows-1 && c == cols-1)
                    return res;
                for(int j = 0; j <4 ; j++){
                    int nextR = X[j] + r;
                    int nextC = Y[j] + c;
                    int nextK = currK;
                    if(nextR>=0 && nextC>=0 && nextR<rows && nextC<cols){
                        if(grid[nextR][nextC] == 1){
                            nextK++;
                        }
                        if(nextK<=k && visited[nextR][nextC][nextK] == 0){
                            visited[nextR][nextC][nextK] = 1;
                            q.push({nextR, nextC, nextK});
                        }
                    }
                }
                
             }
            res++;
            }
        return -1;
           
    }
};
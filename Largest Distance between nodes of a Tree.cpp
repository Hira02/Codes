/*
Problem Description : 
------------------------------------------------------
Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between
any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will
have A[i] equal to -1, it will be root node.
Problem Constraints
1 <= N <= 40000
Input Format
First and only argument is an integer array A of size N.
Output Format
Return a single integer denoting the largest distance between two nodes in a tree.

Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:
 3

Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.
 
 */
 
 Code:
 --------------------------------------------------------------------------------------------
 //  list<int> *edge;
pair<int, int> bfs(int u, int n, vector<int>edge[]){
    int dis[n];
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto itr = edge[top].begin() ; itr != edge[top].end() ; itr++){
            int v = *itr;
            // cout<<v<<" ";
            if(dis[v] == -1){
                q.push(v);
                dis[v] = dis[top]+1;
            }
        }
    }
    int maxDist = 0;
    int node;
    for(int i = 0;i<n;i++){
        if(dis[i]>maxDist)
        {
            maxDist = dis[i];
            node = i;
        }
    }
    return make_pair(node, maxDist);
}
int longestPath(vector<int>edge[], int n){
    pair<int,int> t1, t2;
    t1 = bfs(0, n, edge);
    t2 = bfs(t1.first, n, edge);
    return t2.second;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1)
    return 0;
    if(n == 2)
    return 1;
   vector<int> edge[n];
    
    for(int i = 0 ; i  < n ; i++){
        if(A[i] != -1){
            edge[A[i]].push_back(i);
            edge[i].push_back(A[i]);
        }
    }
    return longestPath(edge, n);
}

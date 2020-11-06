/*
Problem Description : (LC 785)
------------------------------------------------------------------------------------
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split its set of nodes into two independent subsets A and B, 
such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, 
and it doesn't contain any element twice.

 

Example 1:
https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: We cannot find a way to divide the set of nodes into two independent subsets.

 

Constraints:

1 <= graph.length <= 100
0 <= graphp[i].length < 100
0 <= graph[i][j] <= graph.length - 1
graph[i][j] != i
All the values of graph[i] are unique.
The graph is guaranteed to be undirected.
*/
//Code:
//--------------------------------------------------------------------------------------------------------
 class Solution {
public:
    bool check(vector<vector<int>>& graph, int v, int totalVertex, vector<int>& color){
        
        if(color[v] != -1)
            return false;
       color[v] = 1;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto t : graph[top]){
            if(color[t] == -1){
                color[t] = 1-color[top];
                q.push(t);
            
            }else if(color[t] == color[top])
                return false;
         }
    }
         
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
//         unordered_map<int, vector<int>> Map;
//         for(int i = 0 ; i<graph.size() ; i++){
//             for(int j = 0 ; j < graph[i].size() ; j++){
//                  Map[i].push_back(graph[i][j]);
//                  // Map.push_back(graph[i][0]);
//             }
           
//         }
        int V = graph.size();
        vector<int> color(V, -1);
        for(int v = 0 ;v<V ; v++){
            if(color[v] == -1)
                if(check(graph, v, V, color) == false)
                     return false;
        }
        return true;
    }
};
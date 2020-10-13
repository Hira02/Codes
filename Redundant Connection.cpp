/*
Problem Description : (LC 648)
-------------------------------------------------------------------------------------
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v,
 that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers,
 return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/
//Code:
//-----------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& Map, unordered_set<int> visited, int source, int dest){
    if(source == dest)
        return true;
        visited.insert(source);
        for(auto t = Map[source].begin() ; t!= Map[source].end() ; t++){
            // cout<<*t<<" ";
            if(visited.find(*t) == visited.end()){
                if(dfs(Map, visited,*t, dest))
                    return true;
            }
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        unordered_set<int> visited;
        unordered_map<int, vector<int>> Map;
        for(int i = 0 ; i <edges.size() ; i++){
            if(dfs(Map, visited, edges[i][0], edges[i][1]))
               return edges[i];
            Map[edges[i][0]].push_back(edges[i][1]);
            Map[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        return vector<int>{-1, -1};
    }
};
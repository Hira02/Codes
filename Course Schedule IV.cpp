/*
Problem Description : (LC 1462)
----------------------------------------------------------------------
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a pair: [1,0]

Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.

You should answer for each queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1] or not.

Return a list of boolean, the answers to the given queries.

Please note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a prerequisite of course c.

 

Example 1:https://assets.leetcode.com/uploads/2020/04/17/graph-1.png


Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.
Example 2:

Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.
Example 3:

https://assets.leetcode.com/uploads/2020/04/17/graph.png
Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
Example 4:

Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
Output: [false,true]
Example 5:

Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
Output: [true,false,true,false]
 

Constraints:

2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
The prerequisites graph has no cycles.
The prerequisites graph has no repeated edges.
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]

*/

Code:
--------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    
    bool check( unordered_map<int, vector<int>>& graph, int from, int to, vector<vector<int>>& dp){
        // cout<<from<<" "<<to<<" "<<dp[from][to]<<"\n";
      if(dp[from][to] != -1){ // if we have already processed this from-to combo then simply return its value
          return dp[from][to];
      }
        // checking only if current from - to combo hasn't processed
        for(int i = 0 ; i < graph[from].size() ; i++){
            if(graph[from][i] == to || check(graph, graph[from][i], to, dp))
            {
                dp[from][to] = 1;
                return true;
            }
        }
     dp[from][to] = 0;// making it as this from - to combo is processed
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        if(prerequisites.size() == 0)
            return ans;
        // vector<int> graph[n];
        unordered_map<int, vector<int>> graph;
        vector<vector<int>> dp; // this 2D vec will store from-to combo 
         dp.resize(n, vector<int>(n,-1));
        for(auto i : prerequisites){
            graph[i[0]].push_back(i[1]);
            dp[i[0]][i[1]] = 1;
        }
        for(int i = 0 ; i < queries.size() ; i++){
            int from = queries[i][0];
            int to = queries[i][1];
            bool val = check(graph, from, to, dp);
            if(val)
                ans[i] = val;
        }
        return ans;
    }
};

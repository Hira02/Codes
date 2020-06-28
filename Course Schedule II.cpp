/*

Problem Statement : (LC 210)
---------------------------------------------------------------------------------
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

Code:
--------------------------------------------------------------------------------------
class Solution {
public:
        
    bool is_cycle(vector<vector<int>>& prerequisites, int node, vector<int>& visited, vector<int> set[], vector<int>& Stack){
        //using topo sort method
        if(visited[node] == 2)
            return true; // if we find a node which is under processing that means there is a cycle present
        visited[node] = 2; // measn this node is marked as processing
        for(auto v : set[node]){
            if(visited[v] != 1){// if not processed
                if(is_cycle(prerequisites, v, visited, set, Stack))
                    return true;
            }
        }
        visited[node] = 1; // marked node as processed
        Stack.push_back(node);
        return false;      
        
    }
    vector<int> findOrder(int numCourse, vector<vector<int>>& prerequisites) {
         vector<int> set[numCourse];
        for(auto i : prerequisites){
            set[i[1]].push_back(i[0]);
        }
        vector<int> visited(numCourse,0);
        vector<int> Stack;
        vector<int> ans;
        for(int i = 0 ; i < numCourse ; i++){
            if(visited[i] == 0)
                if(is_cycle(prerequisites, i, visited, set, Stack))
                    return ans;
        }
        // for(int i = numCourse-1 ; i>=0 ; i--){
        //     ans.push_back(Stack[i]);
        // }
    return vector<int>(Stack.rbegin(), Stack.rend());
    }
};

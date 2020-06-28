/*

Problem Description : (Lc 207)
-----------------------------------------------------------------------
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/

Code:
--------------------------------------------------------------------------------------------------------------
// topo sort + DFS
class Solution {
public:
    
    bool is_cycle(vector<vector<int>>& prerequisites, int node, vector<int>& visited, vector<int> set[]){
        //using topo sort method
        if(visited[node] == 2)
            return true; // if we find a node which is under processing that means there is a cycle present
        visited[node] = 2; // measn this node is marked as processing
        for(auto v : set[node]){
            if(visited[v] != 1){// if not processed
                if(is_cycle(prerequisites, v, visited, set))
                    return true;
            }
        }
        visited[node] = 1; // marked node as processed
        return false;      
        
    }
    bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {
        
        vector<int> set[numCourse];
        for(auto i : prerequisites){
            set[i[1]].push_back(i[0]);
        }
        vector<int> visited(numCourse,0);
        for(int i = 0 ; i < numCourse ; i++){
            if(visited[i] == 0)
                if(is_cycle(prerequisites, i, visited, set))
                    return false;
        }
        return true;
    }
};

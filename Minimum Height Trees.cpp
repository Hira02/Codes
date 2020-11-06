/*
Problem Description : (LC 310)
-------------------------------------------------------------------------------------------------
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, 
any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any 
node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all
 possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:
https://assets.leetcode.com/uploads/2020/09/01/e1.jpg

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:
https://assets.leetcode.com/uploads/2020/09/01/e2.jpg

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
*/
//Code:
//------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    void createGraph(unordered_map<int, vector<int>> &Map, vector<vector<int>> &edges, int n)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            Map[edges[i][0]].push_back(edges[i][1]);
            Map[edges[i][1]].push_back(edges[i][0]);
        }
    }
    vector<int> bfs(unordered_map<int, vector<int>> &Map, int node, int n)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(node, 0));
        vector<int> storage;
        int maxDepth = 0;
        vector<bool> visited(n, false);
        storage.push_back(node);
        visited[node] = true;
        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            for (auto t : Map[top.first])
            {
                if (!visited[t])
                {
                    if (top.second + 1 > maxDepth)
                    {
                        maxDepth = top.second + 1;
                        storage.push_back(t);
                    }
                    q.push(make_pair(t, top.second + 1));
                    visited[t] = true;
                }
            }
        }
        return storage;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> Map;
        vector<int> ans;
        createGraph(Map, edges, n);
        vector<int> pathStorage;
        pathStorage = bfs(Map, 0, n);
        // cout<<pathStorage.size()<<"\n";
        pathStorage = bfs(Map, pathStorage[pathStorage.size() - 1], n);
        // int len = pathStorage.size();
        cout << pathStorage.size() << "\n";
        if (len % 2 != 0)
            ans.push_back(pathStorage[len / 2]);
        else
        {
            ans.push_back(pathStorage[len / 2]);
            ans.push_back(pathStorage[(len - 1) / 2]);
        }
        return ans;
    }
};
//below link is very helpful : 
//https://stackoverflow.com/questions/63237671/how-many-minimum-height-trees-mhts-can-a-graph-have-at-most#:~:text=So%20at%20most%202%20different,to%20find%20a%20tree's%20diameter.
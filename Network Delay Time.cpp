/*
Problem Description : (LC 743)
-----------------------------------------
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:

https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
*/
Code:
--------------------------------------------------------------------------

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<vector<int>>> m;
        for(int i = 0 ; i < times.size() ; i++){
            vector<int> temp;
            temp.push_back(times[i][1]);
            temp.push_back(times[i][2]);
            m[times[i][0]].push_back(temp);
        }
        /*
        map style:
        u | [[v,w]]
        2 | [[1,1],[3,1]] // 
        1 | []
        3 | [[4,1]]
        4 | []
        */
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        unordered_map<int,int> checker;
        int time = INT_MIN;
        pq.push(make_pair(0,K));
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();
            int dist = top.first;
            int node = top.second;
            // cout<<dist<<" "<<node<<"\n";
            time = max(time,dist);
            if(checker.find(node) != checker.end())
                continue;
            checker[node]= dist;
            for(int i = 0 ; i<m[node].size() ; i++){
                // vector<vector<int>> temp = m[node]
                int newNode = m[node][i][0];
                int newDist = m[node][i][1];
                // cout<<newNode<<" "<<newDist<<"\n";
                if(checker.find(newNode) == checker.end()){
                    pq.push(make_pair(dist+newDist, newNode));
                }                
            }
        }
        if(checker.size() != N)
            return -1;
        int ans = 0;
        for(auto c: checker){
            ans = max(ans,c.second);
        }
        return ans;
        
    }
};

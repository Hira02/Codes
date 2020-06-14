/*
Problem Description : (LC 787)
----------------------------------------------------------------------------
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:

Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:

https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png

The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:

https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png

The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

*/

Code:
------------------------------------------------------------------------------------
typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
     unordered_map<int, vector<pair<int,int>>> mappingSourceDist;
        /*
        map design
        key | value
     source | [<dest, weight>,<dest,weight>....]
        */
     for(int i = 0 ; i < flights.size() ; i++){
         pair<int,int> tempPair = make_pair(flights[i][1], flights[i][2]);
         mappingSourceDist[flights[i][0]].push_back(tempPair);
     }
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.emplace(0, src, K+1); // will be sorted on amount
        while(!pq.empty()){
            ti top = pq.top();
            pq.pop();
            int stop = get<2>(top);
            // cout<<get<0>(top)<<"\n";
            if(get<1>(top) == dst)
                return get<0>(top);
            
            if(stop<=0)
            continue;
            vector<pair<int, int>> vec = mappingSourceDist[get<1>(top)];
            cout<<vec.size()<<"\n";
            // adding all linked neighbours of source
            for(int i = 0 ; i < vec.size() ; i++){
                pair<int,int> tempPair = vec[i];
                pq.emplace(get<0>(top)+tempPair.second, tempPair.first, stop-1);
            }
        }
        return -1;
    }
};

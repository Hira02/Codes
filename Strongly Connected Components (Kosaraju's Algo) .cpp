/*
Problem Description : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

*/
//Code:
//--------------------------------------------------------------------------------------------------------------------
	void mark(int v, stack<int> &Stack, vector<int> &visited, vector<int> adj[]){
	    visited[v] = true;
	    for(auto i : adj[v]){
	       // Stack.push(i);
	       if(visited[i] == false)
	            mark(i, Stack, visited, adj);
	    }
	    Stack.push(v);
	}
	void DFSUtil(int v, vector<int> &visited, vector<int> tran[]){
	    visited[v] = true;
	    for(auto t: tran[v]){
	        if(!visited[t]){
	            DFSUtil(t, visited, tran);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> Stack;
        vector<int> Visited(V, false);
        for(int i = 0 ; i < V ; i++){
            if(!Visited[i]){
                mark(i, Stack, Visited, adj);
            }
        }
        vector<int> tran[V];
        fill(Visited.begin(), Visited.end(), false);
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                tran[adj[i][j]].push_back(i);
            }
        }
        int count = 0;
        while(!Stack.empty()){
            int top = Stack.top();
            Stack.pop();
            if(!Visited[top]){
                DFSUtil(top, Visited, tran);
                count++;
            }
        }
        return count;
    }

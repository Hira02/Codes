/*
Problem Description : InterviewBit HARD
-----------------------------------------------------------------------------------------------
Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.



Problem Constraints
2 <= N <= 105
1 <= M <= 105
1 <= A[i], B[i] <= N
A[i] and B[i] are all distinct.
1 <= C[i][0] < C[i][1] <= N


Input Format
First arguement is an integer array A of size N denoting the permutation A.

Second arguement is an integer array B of size N denoting the permutation B.

Third argument is an 2D integer array C of size M x 2 denoting the M good pairs.



Output Format
If the permutation B can be obtained return 1 else return 0.



Example Input
Input 1:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [ 
        [3, 4]
     ]
Input 2:

 A = [1, 3, 2, 4]
 B = [1, 4, 2, 3]
 C = [
        [2, 4]
     ] 


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 As A != B you have to perform operations on A but there is only good pair available i,e (3, 4) so if you swap
 A3 with A4 you get A = [1, 3, 4, 2] which is not equal to B so we will return 0.
Explanation 2:

 As A != B you have to perform operations on A but there is only good pair available i,e (2, 4) so if you swap
 A2 with A4 you get A = [1, 4, 2, 3] which is equal to B so we will return 1.
 
 */
 
 /*
 Need to understand carefully:
 Let's consider indices as vertices of some graph and allowed pairs as 2-ways edges. Than our graph can be divided in connected components.

The key observation: we can get any permutation of elements in one connected component. And obvisously there is no way to swap to elements that belong to different components. Thus we get simple solution:

Find connected components in our graph.
For each component compare element in permuations P and Q. If these elements differ for at least one component than the answer is "NO" otherwise answer is "YES".
 
 
 */
 
 
 Code:
 --------------------------------------------------------------------------------------------------------------------------
 void dfs(int i, vector<int>& A, vector<int>& B, vector<int>& visited, vector<int>&a, vector<int>& b, unordered_map<int, vector<int>>& Map){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        a.push_back(A[k]);
        b.push_back(B[k]);
        visited[k]= 1;
        for(int i = 0 ; i < Map[k].size() ; i++){
            if(!visited[Map[k][i]]){
                q.push(Map[k][i]);
                visited[Map[k][i]] = 1;
            }
        }
        
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    if(A ==  B)
    return 1;
    unordered_map<int, vector<int>> Map;
    vector<int> visited(A.size(), 0);
    for(int i = 0 ; i < C.size() ; i++){
        Map[C[i][0]-1].push_back(C[i][1]-1);
        Map[C[i][1]-1].push_back(C[i][0]-1);
    }
    vector<int>a;
    vector<int>b;
    for(int i = 0 ; i < A.size() ; i++){
        a.clear();
        b.clear();
        if(!visited[i]){
            dfs(i, A, B, visited, a, b, Map);
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if(a != b)
            return 0;
        }
    }
    return 1;
    
}

/*
Problem Description : (LC 1310)
-------------------------------------------------------
Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.
 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 

Constraints:

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
*/
//Solution approach
---------------------------------------------------------------
/*
There is much simpler solution than the given solution exists.
The idea is to maintain a prefix array which stores the xor of all prefix.
prefix[i] will have xor of elements from 0 to i.
Now xor of L and R will be prefix[R]^prefix[L-1].
How does it works??
We know that xor of any two same values is 0.
Let xor of elements between L and R is P which we have to find.
prefix[R] = prefix[L-1]^P;
so prefix[R]^prefix[L-1] can be written prefix[L-1]^P^prefix[L-1]
and prefix[L-1]^P^prefix[L-1] becomes P because(xor of any two same values is 0)
*/

Code:
-------------------------------------------------------------------
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(30000,0);
        prefix[0] = arr[0];
        vector<int> ans;
        for(int  i = 1 ; i < n ; i++){
         prefix[i] = prefix[i-1]^arr[i];   
        }
        for(int  i = 0 ; i < queries.size() ; i++){
            if(queries[i][0] == 0)
                ans.push_back(prefix[(queries[i][1])]);
            else{
            int val = prefix[(queries[i][1])]^prefix[(queries[i][0]-1)];
             ans.push_back(val);
            }
        }
        return ans;
    }
};

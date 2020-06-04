/*
Problem Description : (LC 373)
----------------------------------------------------
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/
Code:
--------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int, int>>>,greater<pair<int,pair<int,int>>>> pq;
       //tuple (sum,i,j)
       //where i is for nums1 & j for nums2
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
	if (!n or !m) return res;
        for(int i = 0 ; i < nums1.size() ; i++){
            int sum = nums1[i]+nums2[0];
            pq.push(make_pair(sum,make_pair(i,0)));
        }
	while(k && !pq.empty()){
        pair<int,pair<int,int>> top  = pq.top();
        pq.pop();
        int i = top.second.first;
        int j = top.second.second;
        res.emplace_back(vector<int>({nums1[i],nums2[j]}));
        if(j+1<m){
            int sum = nums1[i]+nums2[j+1];
            pq.push(make_pair(sum,make_pair(i,j+1)));
        }
        k--;
    }
	return res;
    }
};

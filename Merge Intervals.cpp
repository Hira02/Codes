/*
Problem Description: (LC 56)
---------------------------------------------------
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
Code:
--------------------------------------------------------------
 bool myComp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
     vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), myComp);
        int index = 0;
        ans.push_back(intervals[0]);
        
        for(int i = 0 ; i < intervals.size() ; i++){
            if(ans[index][1] >= intervals[i][0]){
                ans[index][1] = max(intervals[i][1],ans[index][1]);
            }else{
                index++;
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
//TC : O(nlogn)

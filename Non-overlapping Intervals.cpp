/*
Problem Description : (LC 435)
--------------------------------------------------------------------------------------------------------------------------------------------
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/
//Code:
//-------------------------------------------------------------------------------------------------------
bool myFunction(vector<int> a, vector<int>b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), myFunction);
        int currEnd = intervals[0][1];
        int count = 0 ;
        for(int i = 1 ; i <intervals.size() ; i++){
            if(intervals[i][0]>=currEnd){
               
                 currEnd = intervals[i][1];
            }
            else
                 count++;
           
        }
        return count;
    }
};
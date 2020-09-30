/*
Problem Description : (LC 1235)
------------------------------------------------------------------------
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs 
in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:
https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png


Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:

https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png


Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:

https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4
*/
Code:
-------------------------------------------------------------------------------------------
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> pq;
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            pq.push_back({endTime[i],startTime[index], profit[index]});
            index++;
        }
        sort(pq.begin(), pq.end());
        int result[n];
        result[0] = pq[0][2];
       for(int i = 1; i < n ; i++){
           result[i] = max(pq[i][2], result[i-1]);
            for(int j =i-1 ; j>=0 ; j--){
                if(pq[j][0]<=pq[i][1]){
                    result[i] = max(result[i], pq[i][2]+result[j]);
                    break;
                }
               
            }
        }
        int max_ = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            
              if(max_<result[i])
                  max_=  result[i];
            
        }
        return max_;
        
    }
};
// Suggestion : https://www.youtube.com/watch?v=cr6Ip0J9izc
//https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/WeightedJobSchedulingMaximumProfit.java
// Thanks to Tushar Roy for this greate approach

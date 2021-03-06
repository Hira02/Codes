/*
Problem Description : 
----------------------------------------------------
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/

Code:
----------------------------------------------------------------------
// class countingNumber{
//   public : 
//     int val;
//     int count;
//     countingNumber(x,y) : val(x), count(y){}
// };
class myComp{
  public : 
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        return a.second>b.second;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> tableForCountingNums;
        for(int i = 0 ; i < arr.size() ; i++){            
            tableForCountingNums[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, myComp> pq;
        for(auto c: tableForCountingNums){
            // cout<<c.first<<" "<<c.second<<"\n";
            pair<int,int> arrValueCount = make_pair(c.first,c.second);
            pq.push(arrValueCount);
        }
        while(k>0){
            cout<<pq.top().first<<" "<<pq.top().second<<"\n";
            pair<int,int> top = pq.top();
            pq.pop();
            if(top.second != 1){
            
            // else{
                top.second-=1;
                pq.push(top);
            }
            k--;
        }
        return pq.size();
        
    }
};

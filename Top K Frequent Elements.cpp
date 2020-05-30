/*
Problem Description  :(LC 347)
-----------------------------------------
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

Code:
---------------------------------------------------

class coun{
  public : 
    int x;
    int val;
    coun(int a, int countVal){
        x = a;
        val = countVal;
    }
};
class myComp{
  public : 
    bool operator()(const coun &c, const coun &d){
        return c.val>d.val;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0 ; i < nums.size() ; i++)
            m[nums[i]]++;
        priority_queue<coun, vector<coun>, myComp> pq;
        for(auto c: m){
            pq.push(coun(c.first, c.second));
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        for(int i = 0 ; i < k ; i++){
            coun p = pq.top();
            res.push_back(p.x);
            pq.pop();
        }
        return res;
    }
};

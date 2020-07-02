/*
Problem Description  :(LC 525)
-------------------------------------------
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
Code:
//Approach : 1
-----------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || size == 1)
            return 0;
        vector<int> set;
        map<int, pair<int, int>> m;
        set.push_back(0);
        m[0] = make_pair(0,0);
        // cout<<set[0]<<"\n";
        for(int i=1;i<=size;i++){
            // cout<<"set[i-1]: "<<set[i-1]<<" nums[i-1]"<<nums[i-1]<<"\n";
            int val = (nums[i-1] == 0)?-1:1;
            set.push_back(set[i-1]+val);
            cout<<set[i]<<"\n";
            int sum = set[i];
            if(m.find(sum) == m.end()){
                m[sum] = make_pair(i,0);
            }else{
                pair<int, int> p = m[sum];
                m[sum] = make_pair(p.first, i-p.first);
            }
            // cout<<m[sum];
        }
        // cout<<set.size();
        map<int, pair<int, int>> :: iterator itr;
        int max = 0;
        for(itr = m.begin();itr != m.end(); itr++){
            pair<int, int> p = itr->second;
            cout<<p.second<<"\n";
            if(max<p.second)
                max = p.second;
        }
        return max;
    }
};
//Approach : 2
----------------------------------------------------------------------------------------------------------------
    class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     unordered_map<int, int> Map;
        int max_length = 0;
        int count = 0;
        Map[0] = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            count += (nums[i] == 0)?-1:1;
            if(Map.find(count) != Map.end()){
                max_length = max(max_length, i-Map[count]);
            }else{
                Map[count] = i;
            }
        }
        return max_length;
    }
};



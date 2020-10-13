/*
Problem Description : (LC 220)
-----------------------------------------------------------------------------------------------------------
Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

//Code:
//@Copy : https://leetcode.com/problems/contains-duplicate-iii/discuss/61774/Accept-C%2B%2B-Solution
/*
Approach:  
----------
1. Using a sliding window of size k
2. Using a multiset because all elements will be in sorted order and we can enter duplicates as well
3. when ever we are exceeding the window size of k, need to remove the first element from the window as well as from the set
4. now Our target is to find a set of elements whose diff is t. 
5. Whenever say for arr[i] we are checking : if there is any element present which is equal to arr[i]-t say arr[j]
then we can say we have found. Because
Given : |arr[j]-arr[i]|<=t 
-t<= (arr[j]-arr[i])<= t
arr[i]-t<=arr[j]<=arr[i]+t
also, if the lower_bound iterator returns a value which is not greater than arr[i]+t and also not end of arr then also it is true
6. but if there is any element present which is greater  than arr[i] -t then we also need to check if that value is greater than 
arr[i]+t or not. To make the answer true the greater value should be less than (arr[i]+t) else we can add this arr[i] into 
out window and set.
*/
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       if (nums.size() < 2 || k == 0)
            return false;
        deque<int> windows_deq;
        multiset<long> windows;
        for (int i = 0; i < nums.size(); i++) {
            if (windows.size() > k) {
                int num = windows_deq.front();
                windows_deq.pop_front();
                windows.erase(windows.find(num));
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                // not found
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};